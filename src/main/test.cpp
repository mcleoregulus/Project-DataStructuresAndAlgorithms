
#include <iostream>
// #include "../include/Graphm.hpp"
#include "../include/CircuitGraph.hpp"
#include "../include/Utils.hpp"
// #include "../include/CSVImporter.hpp"
//#include "../include/CSVExporter.hpp"
// #include "Djsktra.cpp"

using namespace std;

int main() {
    CircuitGraph my_circuit(4);
    // printMatrix(my_circuit.getAdjMatrix());
    // printMatrix(my_circuit.admitMatrix());

    my_circuit.setEdge(0, 1, {2, 4});
    my_circuit.setEdge(1, 0, {2, 4});

    my_circuit.setBranch(1, 2, {2, 4});
    my_circuit.setBranch(1, 3, {1, 1});
    my_circuit.setBranch(2, 4, {3, 4});
    my_circuit.setBranch(3, 4, {1, 2});

    printMatrix(my_circuit.getAdjMatrix());
    printMatrix(my_circuit.admitMatrix());

    // CSVImporter importer("../data/example.csv");

    // auto adjMatrix = importer.getAdjMatrix();
    // auto nodeMapping = importer.getNodeMapping();

    // // 输出邻接矩阵
    // std::cout << "Adjacency Matrix:" << std::endl;
    // for (const auto& row : adjMatrix) {
    //     for (const auto& val : row) {
    //         std::cout << "(" << val.real() << ", " << val.imag() << ") ";
    //     }
    //     std::cout << std::endl;
    // }

    // // 输出节点映射
    // std::cout << "\nNode Mapping:" << std::endl;
    // for (const auto& pair : nodeMapping) {
    //     std::cout << pair.first << " -> " << pair.second << std::endl;
    // }

    
    // my_circuit.delVertex(2);
    // printMatrix(my_circuit.adjMatrix());
    // printMatrix(my_circuit.admitMatrix());
    // cout << my_circuit.n();



    // Graphm my_graph(4);     //无向图，电力系统分析 part2 tab2

    // my_graph.setEdge(0, 1, {2,-6});
    // my_graph.setEdge(1, 0, {2,-6});

    // my_graph.setEdge(0, 2, {1,-3});
    // my_graph.setEdge(2, 0, {1,-3});

    // my_graph.setEdge(1, 2, {2/3,-2});
    // my_graph.setEdge(2, 1, {2/3,-2});

    // my_graph.setEdge(1, 3, {1,-3});
    // my_graph.setEdge(3, 1, {1,-3});

    // my_graph.setEdge(2, 3, {2,-6});
    // my_graph.setEdge(3, 2, {2,-6});

    // // vector<vector<complex<double>>> admitmatrix = my_graph.admitMatrix();
    // vector<vector<complex<double>>> adjmatrix = my_graph.adjMatrix();
    // my_graph.printMatrix(adjmatrix);    // 打印邻接矩阵
    // cout << endl;
    // // my_graph.printMatrix(admitmatrix);  // 打印导纳矩阵

    // // my_graph.addVertex(); // 新增节点
    // my_graph.delVertex(2);   // 删除指定节点
    // adjmatrix = my_graph.adjMatrix();
    // my_graph.printMatrix(adjmatrix);    // 打印邻接矩阵


    // int f = my_graph.first(1);
    // bool a = my_graph.isEdge(2, 3);
    // bool b = my_graph.isEdge(3, 2);
    // complex<double> w = my_graph.weight(2, 3);

    // int e = my_graph.e();
    // int n = my_graph.n();

    // cout << ": " << a << " " << b << " " << e << " " << n << " " << w << " " << f;

    return 0;
}