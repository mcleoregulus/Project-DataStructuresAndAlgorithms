
#include <iostream>
#include <iomanip>
#include <fstream>
#include "../include/CircuitSimulator.hpp"
#include "../include/CircuitVisualizer.hpp"
#include "../include/Utils.hpp"

using namespace std;

// 辅助函数：打印复数
void printComplex(Complex c) {
    cout << fixed << setprecision(4) 
         << c.real() << (c.imag() >= 0 ? "+" : "") << c.imag() << "j";
}

int main() {
    Graphl circuit;
    importFromCSV("config", circuit);
    circuit.printAdjList();

    // 创建电路仿真器
    CircuitSimulator simulator(circuit);

    // 设置电压源和电流源
    simulator.setVoltageSource(0, Complex(220, 0));  // 节点1设置为220V
    // simulator.setVoltageSource(1, Complex(10, 90));  // 节点1设置为220V

    simulator.setReferenceNode();
    // simulator.setCurrentSource(2, Complex(10, 0));   // 节点3注入10A电流

    // 执行电路分析
    simulator.analyze();

    // 获取并打印结果
    cout << "Node Voltage: " << endl;
    const auto& voltages = simulator.getNodeVoltages();
    for(int i = 0; i < voltages.size(); i++) {
        cout << "V" << (i+1) << " = ";
        printComplex(voltages[i]);
        cout << " V" << endl;
    }

    cout << "\nBranch current: " << endl;
    const auto& currents = simulator.getBranchCurrents();
    int branchIndex = 0;
    for(int i = 0; i < circuit.n(); i++) {
        for(int j = i + 1; j < circuit.n(); j++) {
            if(circuit.getAdjMatrix()[i][j] != Complex(0, 0)) {
                cout << "I" << (i+1) << "-" << (j+1) << " = ";
                printComplex(currents[branchIndex++]);
                cout << " A" << endl;
            }
        }
    }

    // cout << "\nBranch power" << endl;
    // const auto& powers = simulator.getBranchPowers();
    // branchIndex = 0;
    // for(int i = 0; i < circuit.n(); i++) {
    //     for(int j = i + 1; j < circuit.n(); j++) {
    //         if(circuit.getAdjMatrix()[i][j] != Complex(0, 0)) {
    //             cout << "S" << (i+1) << "-" << (j+1) << " = ";
    //             printComplex(powers[branchIndex++]);
    //             cout << " VA" << endl;
    //         }
    //     }
    // }

    // 创建可视化工具
    // CircuitVisualizer visualizer(simulator, circuit);
    
    // 生成DOT文件
    // visualizer.generateDotFile("circuit.dot");
    
    // 生成PNG图像（需要安装Graphviz）
    // visualizer.generatePNG("circuit.dot", "circuit.png");
    
    // cout << "\nGenerated circuit.dot and circuit.png" << endl;

    return 0;
} 