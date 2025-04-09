
#include <iostream>
#include <iomanip>
#include <fstream>
#include "../include/CircuitSimulator.hpp"
#include "../include/CircuitVisualizer.hpp"
#include "../include/Utils.hpp"

using namespace std;

// 辅助函数：打印复数
void printComplex(Complex c)
{
    cout << fixed << setprecision(4)
         << c.real() << (c.imag() >= 0 ? "+" : "") << c.imag() << "j";
}

int main()
{
    Graphl circuit;
    importFromCSV("config2", circuit);
    circuit.printAdjList();

    // 创建电路仿真器
    CircuitSimulator simulator(circuit);

    // 设置电压源和电流源
    simulator.setVoltageSource(0, Complex(220, 0)); // 节点1设置为220V
    // simulator.setVoltageSource(1, Complex(220, 0));  // 节点2设置为220V
    simulator.setReferenceNode(); // 默认最后一个节点为参考节点，电压设为0

    // simulator.setCurrentSource(2, Complex(10, 0));   // 节点3注入10A电流

    // 执行电路分析
    simulator.analyze();

    // 获取并打印结果
    cout << "Node Voltage: " << endl;
    const auto &voltages = simulator.getNodeVoltages();
    for (int i = 0; i < voltages.size(); i++)
    {
        double magnitude = abs(voltages[i]);                    // 模
        double phase = arg(voltages[i]) * 180 / M_PI; // 幅角，转换为度
        cout << fixed << setprecision(4);
        cout << "V" << (i + 1) << " = ";
        // api dosomthing()
        cout << magnitude << " |_" << phase << " V" << endl;
    }

    cout << "\nBranch current: " << endl;
    const auto &currents = simulator.getBranchCurrents();
    int branchIndex = 0;
    for (int i = 0; i < circuit.n(); i++)
    {
        for (int j = i + 1; j < circuit.n(); j++)
        {
            if (circuit.getAdjMatrix()[i][j] != Complex(0, 0))
            {
                double magnitude = abs(currents[branchIndex]); // 模
                double phase = arg(currents[branchIndex]) * 180 / M_PI; // 幅角
                cout << "I" << (i + 1) << "-" << (j + 1) << " = ";
                // api dosomthing()
                cout << magnitude << " |_" << phase << " A" << endl;
                branchIndex++;
            }
        }
    }

    cout << "\nBranch power" << endl;
    const auto& powers = simulator.getBranchPowers();
    branchIndex = 0;
    for(int i = 0; i < circuit.n(); i++) {
        for(int j = i + 1; j < circuit.n(); j++) {
            if(circuit.getAdjMatrix()[i][j] != Complex(0, 0)) {
                double active = real(powers[branchIndex]); // 有功
                double reactive = imag(powers[branchIndex]); // 无功
                // api dosomthing()
                cout << "S" << (i+1) << "-" << (j+1) << " = ";
                // printComplex(powers[branchIndex]);
                cout << active << (reactive>= 0 ? "+" : "") << reactive << "j";
                cout << " VA" << endl;
                branchIndex++;
            }
        }
    }

    // 创建可视化工具
    // CircuitVisualizer visualizer(simulator, circuit);

    // 生成DOT文件
    // visualizer.generateDotFile("circuit.dot");

    // 生成PNG图像（需要安装Graphviz）
    // visualizer.generatePNG("circuit.dot", "circuit.png");

    // cout << "\nGenerated circuit.dot and circuit.png" << endl;

    return 0;
}