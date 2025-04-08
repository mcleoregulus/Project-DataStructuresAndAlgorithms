#include "../include/CircuitSimulator.hpp"
#include "../include/CircuitVisualizer.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

// 辅助函数：打印复数
void printComplex(complex<double> c) {
    cout << fixed << setprecision(4) 
         << c.real() << (c.imag() >= 0 ? "+" : "") << c.imag() << "j";
}

int main() {
    // 创建一个简单的测试电路
    // 假设是一个4节点的电路
    CircuitGraph circuit(4);
    
    // 设置支路阻抗
    // 节点1-2之间的阻抗为2+j1
    circuit.setBranch(1, 2, complex<double>(2, 1));
    // 节点2-3之间的阻抗为1+j0.5
    circuit.setBranch(2, 3, complex<double>(1, 0.5));
    // 节点3-4之间的阻抗为3+j1.5
    circuit.setBranch(3, 4, complex<double>(3, 1.5));
    // 节点4-1之间的阻抗为2+j1
    circuit.setBranch(4, 1, complex<double>(2, 1));

    // 创建电路仿真器
    CircuitSimulator simulator(circuit);

    // 设置电压源和电流源
    simulator.setVoltageSource(0, complex<double>(220, 0));  // 节点1设置为220V
    simulator.setCurrentSource(2, complex<double>(10, 0));   // 节点3注入10A电流

    // 执行电路分析
    simulator.analyze();

    // 获取并打印结果
    cout << "节点电压：" << endl;
    const auto& voltages = simulator.getNodeVoltages();
    for(int i = 0; i < voltages.size(); i++) {
        cout << "V" << (i+1) << " = ";
        printComplex(voltages[i]);
        cout << " V" << endl;
    }

    cout << "\n支路电流：" << endl;
    const auto& currents = simulator.getBranchCurrents();
    int branchIndex = 0;
    for(int i = 0; i < circuit.n(); i++) {
        for(int j = i + 1; j < circuit.n(); j++) {
            if(circuit.getAdjMatrix()[i][j] != complex<double>(0, 0)) {
                cout << "I" << (i+1) << "-" << (j+1) << " = ";
                printComplex(currents[branchIndex++]);
                cout << " A" << endl;
            }
        }
    }

    cout << "\n支路功率：" << endl;
    const auto& powers = simulator.getBranchPowers();
    branchIndex = 0;
    for(int i = 0; i < circuit.n(); i++) {
        for(int j = i + 1; j < circuit.n(); j++) {
            if(circuit.getAdjMatrix()[i][j] != complex<double>(0, 0)) {
                cout << "S" << (i+1) << "-" << (j+1) << " = ";
                printComplex(powers[branchIndex++]);
                cout << " VA" << endl;
            }
        }
    }

    // 创建可视化工具
    CircuitVisualizer visualizer(simulator, circuit);
    
    // 生成DOT文件
    visualizer.generateDotFile("circuit.dot");
    
    // 生成PNG图像（需要安装Graphviz）
    visualizer.generatePNG("circuit.dot", "circuit.png");
    
    cout << "\n已生成电路图形文件：circuit.dot 和 circuit.png" << endl;

    return 0;
} 