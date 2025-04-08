#ifndef CIRCUIT_SIMULATOR_HPP
#define CIRCUIT_SIMULATOR_HPP

#include "CircuitGraph.hpp"
#include <Eigen/Dense>
#include <vector>
#include <complex>
#include <map>
#include <string>

using namespace std;
using namespace Eigen;

class CircuitSimulator {
private:
    CircuitGraph& circuit;
    vector<complex<double>> nodeVoltages;
    vector<complex<double>> branchCurrents;
    vector<complex<double>> branchPowers;
    map<int, complex<double>> voltageSources;  // 节点电压源
    map<int, complex<double>> currentSources;  // 节点电流源

public:
    CircuitSimulator(CircuitGraph& cg) : circuit(cg) {
        nodeVoltages.resize(circuit.n(), complex<double>(0, 0));
        // 初始化其他向量
        initializeVectors();
    }

    void initializeVectors() {
        int n = circuit.n();
        branchCurrents.clear();
        branchPowers.clear();
        
        // 为每个可能的支路预分配空间
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(circuit.getAdjMatrix()[i][j] != complex<double>(0, 0)) {
                    branchCurrents.push_back(complex<double>(0, 0));
                    branchPowers.push_back(complex<double>(0, 0));
                }
            }
        }
    }

    // 设置电压源
    void setVoltageSource(int node, complex<double> voltage) {
        voltageSources[node] = voltage;
    }

    // 设置电流源
    void setCurrentSource(int node, complex<double> current) {
        currentSources[node] = current;
    }

    // 求解节点电压
    void solveNodeVoltages() {
        int n = circuit.n();
        MatrixXcd Y = MatrixXcd::Zero(n, n);
        VectorXcd I = VectorXcd::Zero(n);

        // 构建导纳矩阵
        auto admitMatrix = circuit.getAdmitMatrix();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                Y(i, j) = admitMatrix[i][j];
            }
        }

        // 添加电流源
        for(const auto& [node, current] : currentSources) {
            I(node) = current;
        }

        // 处理电压源约束
        for(const auto& [node, voltage] : voltageSources) {
            // 修改矩阵行，使得该节点电压被固定
            Y.row(node).setZero();
            Y(node, node) = 1.0;
            I(node) = voltage;
        }

        // 求解方程 Y * V = I
        VectorXcd V = Y.colPivHouseholderQr().solve(I);

        // 保存结果
        for(int i = 0; i < n; i++) {
            nodeVoltages[i] = V(i);
        }
    }

    // 计算支路电流
    void calculateBranchCurrents() {
        int n = circuit.n();
        int branchIndex = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(circuit.getAdjMatrix()[i][j] != complex<double>(0, 0)) {
                    complex<double> impedance = circuit.getAdjMatrix()[i][j];
                    complex<double> current = (nodeVoltages[i] - nodeVoltages[j]) / impedance;
                    branchCurrents[branchIndex++] = current;
                }
            }
        }
    }

    // 计算功率分布
    void calculatePowerDistribution() {
        int n = circuit.n();
        int branchIndex = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(circuit.getAdjMatrix()[i][j] != complex<double>(0, 0)) {
                    complex<double> current = branchCurrents[branchIndex];
                    complex<double> voltage = nodeVoltages[i] - nodeVoltages[j];
                    branchPowers[branchIndex] = voltage * conj(current);
                    branchIndex++;
                }
            }
        }
    }

    // 获取节点电压
    const vector<complex<double>>& getNodeVoltages() const {
        return nodeVoltages;
    }

    // 获取支路电流
    const vector<complex<double>>& getBranchCurrents() const {
        return branchCurrents;
    }

    // 获取支路功率
    const vector<complex<double>>& getBranchPowers() const {
        return branchPowers;
    }

    // 执行完整的电路分析
    void analyze() {
        solveNodeVoltages();
        calculateBranchCurrents();
        calculatePowerDistribution();
    }
};

#endif // CIRCUIT_SIMULATOR_HPP 