
#include <iostream>
// #include "../include/Graphm.hpp"
// #include "../include/CircuitGraph.hpp"
// #include "../include/CSVImporter.hpp"
//#include "../include/CSVExporter.hpp"
// #include "Djsktra.cpp"

#include "../include/Utils.hpp"
#include "../include/Graphl.hpp"
#include "../include/CircuitGraphl.hpp"


using namespace std;

int main() {

    CircuitGraphl my_graph(4);
    // my_graph.printAdmitMatrix();
    // cout << adj_list[0]->getValue().weight();

    // Graphl my_graph(4);

    my_graph.setEdge(0, 1, {2,-6});
    my_graph.setEdge(1, 0, {2,-6});

    my_graph.setEdge(0, 2, {1,-3});
    my_graph.setEdge(2, 0, {1,-3});

    my_graph.setEdge(1, 2, {2/3,-2});
    my_graph.setEdge(2, 1, {2/3,-2});

    my_graph.setEdge(1, 3, {1,-3});
    my_graph.setEdge(3, 1, {1,-3});

    my_graph.setEdge(2, 3, {2,-6});
    my_graph.setEdge(3, 2, {2,-6});

    cout << my_graph.n() << endl;
    my_graph.getAdmitMatrix();


    // int f = my_graph.first(1);
    // int next = my_graph.next(1, 0);
    // bool a = my_graph.isEdge(2, 3);
    // bool b = my_graph.isEdge(3, 2);
    // Complex w = my_graph.weight(2, 3);

    // int e = my_graph.e();
    // int n = my_graph.n();

    // cout << my_graph.getMark(1) << endl;
    // my_graph.setMark(1, VISITED);
    // cout << my_graph.getMark(1) << endl;

    // cout << ": " << a << " " << b << " " << e << " " << n << " " << w << " " << f << " " << next;

    // // vector<vector<Complex>> admitmatrix = my_graph.admitMatrix();
    // vector<vector<Complex>> adjmatrix = my_graph.adjMatrix();
    // my_graph.printMatrix(adjmatrix);    // 打印邻接矩阵
    // cout << endl;
    // // my_graph.printMatrix(admitmatrix);  // 打印导纳矩阵

    // // my_graph.addVertex(); // 新增节点
    // my_graph.delVertex(2);   // 删除指定节点
    // adjmatrix = my_graph.adjMatrix();
    // my_graph.printMatrix(adjmatrix);    // 打印邻接矩阵


    // my_graph.setEdge(0, 3, {1, 2});
    // my_graph.setEdge(0, 2, {1, 4});

    // cout << my_graph.weight(0, 2) << endl;
    // my_graph.delEdge(0, 2);
    // cout << my_graph.weight(0, 2) << endl;



    // Graphm my_graph(4);



    // CircuitGraph my_circuit(0);
    // importFromCSV("example", my_circuit);
    // printMatrix(my_circuit.getAdjMatrix());
    // printMatrix(my_circuit.getAdmitMatrix());


    // CircuitGraph my_circuit(4);
    // printMatrix(my_circuit.getAdjMatrix());
    // printMatrix(my_circuit.admitMatrix());

    // my_circuit.setBranch(1, 2, {2, 4});
    // my_circuit.setBranch(1, 3, {1, 1});
    // my_circuit.setBranch(2, 4, {3, 4});
    // my_circuit.setBranch(3, 4, {1, 2});

    // printMatrix(my_circuit.getAdjMatrix());
    // printMatrix(my_circuit.getAdmitMatrix());

    // cout << my_circuit.weight(0, 1);

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





    return 0;
}