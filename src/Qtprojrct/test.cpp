
// 测试用例

#include <iostream>
#include <iomanip>
#include <fstream>
#include "../include/Graphl.hpp"
#include "../include/Utils.hpp"
#include "../include/Floyd.hpp"
#include "../include/CircuitSimulator.hpp"
#include "../include/CircuitVisualizer.hpp"


using namespace std;

int main() {

    Graphl circuit;
    importFromCSV(circuit, "example");
    // 打印邻接表
    circuit.printAdjList();

    // 创建电路仿真器
    CircuitSimulator simulator(circuit);

    // 设置电压源和电流源
    simulator.setVoltageSource(0, Complex(220, 0)); // 节点1设置为220V
    simulator.setVoltageSource(1, Complex(220, 0));  // 节点2设置为220V
    simulator.setReferenceNode(); // 默认最后一个节点为参考节点，电压设为0
    // simulator.setCurrentSource(2, Complex(10, 0));   // 节点3注入10A电流

    // 执行电路分析
    simulator.analyze();

    // 获取并打印结果
    simulator.printNodeVoltages();
    simulator.printBranchCurrents();
    simulator.printBranchPowers();

    // 增加节点
    circuit.addVertex();
    circuit.setBranch(5, 3, {2, -4});
    cout << "Adjacent list after add vertex: \n";
    circuit.printAdjList();
    // 删除指定节点
    circuit.delVertex(2);
    // 设置支路阻抗
    circuit.setBranch(1, 4, {2, 4});
    // 设置标记数组
    circuit.setMark(2, VISITED);
    // 打印标记数组
    circuit.printMark();

    // 打印邻接矩阵和导纳矩阵
    cout << "Adjacent list after delete vertex: \n";
    circuit.printAdjList();
    cout << "Adjacent matrix: \n";
    printMatrix(circuit.getAdjMatrix(), circuit.n());
    cout << "Admittance matrix: \n";
    circuit.printAdmitMatrix();

    // 弗洛伊德最短路径分析
    Floyd(&circuit);



    return 0;
}