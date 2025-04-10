#ifndef CIRCUIT_SIMULATOR_HPP
#define CIRCUIT_SIMULATOR_HPP

#include "../../libs/eigen-3.4.0/Eigen/Dense"
#include "Graphl.hpp"
#include <vector>
#include <complex>
#include <map>
#include <string>
#include <iomanip>

using namespace std;
using namespace Eigen;

class CircuitSimulator
{
private:
    Graphl &circuit;
    vector<complex<double>> nodeVoltages;
    vector<complex<double>> branchCurrents;
    vector<complex<double>> branchPowers;
    map<int, complex<double>> voltageSources; // 节点电压源
    map<int, complex<double>> currentSources; // 节点电流源

public:
    CircuitSimulator(Graphl &cg) : circuit(cg)
    {
        nodeVoltages.resize(circuit.n(), complex<double>(0, 0));
        // 初始化其他向量
        initializeVectors();
    }

    void initializeVectors()
    {
        int n = circuit.n();
        branchCurrents.clear();
        branchPowers.clear();

        // 为每个可能的支路预分配空间
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (circuit.getAdjMatrix()[i][j] != complex<double>(0, 0))
                {
                    branchCurrents.push_back(complex<double>(0, 0));
                    branchPowers.push_back(complex<double>(0, 0));
                }
            }
        }
    }

    // 设置电压源
    void setVoltageSource(int node, complex<double> voltage)
    {
        voltageSources[node] = voltage;
    }

    // 设置电流源
    void setCurrentSource(int node, complex<double> current)
    {
        currentSources[node] = current;
    }

    // 求解节点电压
    void solveNodeVoltages()
    {
        int n = circuit.n();
        MatrixXcd Y = MatrixXcd::Zero(n, n);
        VectorXcd I = VectorXcd::Zero(n);

        // 构建导纳矩阵
        auto admitMatrix = circuit.getAdmitMatrix();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                Y(i, j) = admitMatrix[i][j];
            }
        }

        // 添加电流源
        for (const auto &[node, current] : currentSources)
        {
            I(node) = current;
        }

        // 处理电压源约束
        for (const auto &[node, voltage] : voltageSources)
        {
            // 修改矩阵行，使得该节点电压被固定
            Y.row(node).setZero();
            Y(node, node) = 1.0;
            I(node) = voltage;
        }

        // 求解方程 Y * V = I
        VectorXcd V = Y.colPivHouseholderQr().solve(I);

        // 保存结果
        for (int i = 0; i < n; i++)
        {
            nodeVoltages[i] = V(i);
        }
    }

    // 计算支路电流
    void calculateBranchCurrents()
    {
        int n = circuit.n();
        int branchIndex = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (circuit.getAdjMatrix()[i][j] != complex<double>(0, 0))
                {
                    complex<double> impedance = circuit.getAdjMatrix()[i][j];
                    complex<double> current = (nodeVoltages[i] - nodeVoltages[j]) / impedance;
                    branchCurrents[branchIndex++] = current;
                }
            }
        }
    }

    // 计算功率分布
    void calculatePowerDistribution()
    {
        int n = circuit.n();
        int branchIndex = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (circuit.getAdjMatrix()[i][j] != complex<double>(0, 0))
                {
                    complex<double> current = branchCurrents[branchIndex];
                    complex<double> voltage = nodeVoltages[i] - nodeVoltages[j];
                    branchPowers[branchIndex] = voltage * conj(current);
                    branchIndex++;
                }
            }
        }
    }

    // 获取节点电压
    const vector<complex<double>> &getNodeVoltages() const
    {
        return nodeVoltages;
    }

    // 获取支路电流
    const vector<complex<double>> &getBranchCurrents() const
    {
        return branchCurrents;
    }

    // 获取支路功率
    const vector<complex<double>> &getBranchPowers() const
    {
        return branchPowers;
    }

    // 执行完整的电路分析
    void analyze()
    {
        solveNodeVoltages();
        calculateBranchCurrents();
        calculatePowerDistribution();
    }

    void setReferenceNode(int n = -1)
    {
        n = n == -1 ? circuit.n() - 1 : n;
        setVoltageSource(n, {0, 0});
    }

    void printNodeVoltages()
    {
        cout << "Node Voltage: " << endl;
        const auto &voltages = getNodeVoltages();
        for (int i = 0; i < voltages.size(); i++)
        {
            double magnitude = abs(voltages[i]);          // 模
            double phase = arg(voltages[i]) * 180 / M_PI; // 幅角，转换为度
            cout << fixed << setprecision(4);
            cout << "V" << (i + 1) << " = ";
            // api dosomthing()
            cout << magnitude << " |_" << phase << " V" << endl;
        }
    }

    void printBranchCurrents()
    {
        cout << "\nBranch current: " << endl;
        const auto &currents = getBranchCurrents();
        int branchIndex = 0;
        for (int i = 0; i < circuit.n(); i++)
        {
            for (int j = i + 1; j < circuit.n(); j++)
            {
                if (circuit.getAdjMatrix()[i][j] != Complex(0, 0))
                {
                    double magnitude = abs(currents[branchIndex]);          // 模
                    double phase = arg(currents[branchIndex]) * 180 / M_PI; // 幅角
                    cout << "I" << (i + 1) << "-" << (j + 1) << " = ";
                    // api dosomthing()
                    cout << magnitude << " |_" << phase << " A" << endl;
                    branchIndex++;
                }
            }
        }
    }

    void printBranchPowers()
    {
        cout << "\nBranch power" << endl;
        const auto &powers = getBranchPowers();
        int branchIndex = 0;
        for (int i = 0; i < circuit.n(); i++)
        {
            for (int j = i + 1; j < circuit.n(); j++)
            {
                if (circuit.getAdjMatrix()[i][j] != Complex(0, 0))
                {
                    double active = real(powers[branchIndex]);   // 有功
                    double reactive = imag(powers[branchIndex]); // 无功
                    // api dosomthing()
                    cout << "S" << (i + 1) << "-" << (j + 1) << " = ";
                    // printComplex(powers[branchIndex]);
                    cout << active << (reactive >= 0 ? "+" : "") << reactive << "j";
                    cout << " VA" << endl;
                    branchIndex++;
                }
            }
        }
    }
};

#endif // CIRCUIT_SIMULATOR_HPP