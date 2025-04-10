#include "../include/CircuitSimulator.hpp"
#include "../include/Floyd.hpp"
#include "../include/Graphl.hpp"
#include "../include/Utils.hpp"
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>

using namespace std;

void printMenu()
{
    cout << "\n===== 电路分析系统 =====\n";
    cout << "1. 添加节点\n";
    cout << "2. 删除节点\n";
    cout << "3. 删除阻抗\n";
    cout << "4. 设置/修改阻抗\n";
    cout << "5. 执行电路分析\n";
    cout << "6. 最短路径分析(Floyd)\n";
    cout << "0. 退出系统\n";
    cout << "请选择操作(0-6): ";
}

void handleAddVertex(Graphl &circuit)
{
    circuit.addVertex();
    cout << "节点添加成功！当前邻接表：" << endl;
    circuit.printAdjList();
}

void handleDelVertex(Graphl &circuit)
{
    cout << "输入要删除的节点编号(留空删除最后一个节点): ";
    string input;
    getline(cin, input);

    int node = -1; // 默认删除最后一个节点
    if (!input.empty())
    {
        try
        {
            node = stoi(input);
        }
        catch (...)
        {
            cout << "无效输入！请输入数字" << endl;
            return;
        }
    }

    if (circuit.delVertex(node))
    {
        cout << "节点删除成功！当前邻接表：" << endl;
        circuit.printAdjList();
    }
    else
    {
        cout << "节点不存在或删除失败！" << endl;
    }
}

void handleDelEdge(Graphl &circuit)
{
    cout << "输入要删除阻抗的两个节点编号(用空格分隔): ";
    string input;
    getline(cin, input);
    stringstream ss(input);

    int node1, node2;
    if (!(ss >> node1 >> node2))
    {
        cout << "输入格式错误！" << endl;
        return;
    }

    if (node1 == node2)
    {
        cout << "节点不能相同！" << endl;
        return;
    }

    if (circuit.isEdge(node1, node2))
    {
        circuit.delEdge(node1, node2);
        circuit.delEdge(node2, node1); // 双向删除
        cout << "阻抗删除成功！当前邻接表：" << endl;
        circuit.printAdjList();
    }
    else
    {
        cout << "节点" << node1 << "和" << node2 << "之间不存在阻抗！" << endl;
    }
}

void handleSetEdge(Graphl &circuit)
{
    cout << "输入阻抗的两个节点编号(用空格分隔): ";
    string nodesInput;
    getline(cin, nodesInput);
    stringstream nodesSS(nodesInput);

    int node1, node2;
    if (!(nodesSS >> node1 >> node2))
    {
        cout << "节点输入格式错误！" << endl;
        return;
    }

    if (node1 == node2)
    {
        cout << "节点不能相同！" << endl;
        return;
    }

    cout << "输入电阻和电抗值(用空格分隔): ";
    string valuesInput;
    getline(cin, valuesInput);
    stringstream valuesSS(valuesInput);

    double resistance, reactance;
    if (!(valuesSS >> resistance >> reactance))
    {
        cout << "阻抗值输入格式错误！" << endl;
        return;
    }

    if (resistance < 0)
    {
        cout << "电阻值不能为负！" << endl;
        return;
    }
    circuit.setEdge(node1, node2, {resistance, reactance});
    circuit.setEdge(node2, node1, {resistance, reactance});
    cout << "阻抗设置成功！当前邻接表：" << endl;
    circuit.printAdjList();
}

void handleAnalyze(Graphl &circuit)
{
    CircuitSimulator simulator(circuit);
    simulator.setVoltageSource(0, Complex(220, 0)); // 默认设置节点0为220V
    simulator.setReferenceNode();                   // 默认最后一个节点为参考节点

    cout << "\n===== 电路分析结果 =====\n";
    simulator.analyze();
    simulator.printNodeVoltages();
    simulator.printBranchCurrents();
    simulator.printBranchPowers();
}

int main()
{
    Graphl circuit;
    importFromCSV(circuit, "example");

    while (true)
    {
        cout << "\n当前电路邻接表：" << endl;
        circuit.printAdjList();

        printMenu();
        string choiceStr;
        getline(cin, choiceStr);

        if (choiceStr.empty())
            continue;

        try
        {
            int choice = stoi(choiceStr);

            switch (choice)
            {
            case 0:
                cout << "退出系统。" << endl;
                return 0;
            case 1:
                handleAddVertex(circuit);
                break;
            case 2:
                handleDelVertex(circuit);
                break;
            case 3:
                handleDelEdge(circuit);
                break;
            case 4:
                handleSetEdge(circuit);
                break;
            case 5:
                handleAnalyze(circuit);
                break;
            case 6:
                cout << "\n===== 最短路径分析 =====\n";
                Floyd(&circuit);
                break;
            default:
                cout << "无效操作，请重新选择！" << endl;
            }
        }
        catch (...)
        {
            cout << "输入无效，请输入数字！" << endl;
        }
    }

    return 0;
}