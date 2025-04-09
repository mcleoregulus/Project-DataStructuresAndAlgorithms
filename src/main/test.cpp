
#include <iostream>
#include "../include/Graphl.hpp"
#include "../include/Utils.hpp"
#include "../include/Floyd.hpp"

using namespace std;

int main() {

    Graphl my_circuit;
    // Graphl my_circuit(4); // 默认生成空图
    
    // cout << my_circuit.n() << endl;

    importFromCSV("config", my_circuit);
    my_circuit.delVertex();
    importFromCSV("example2", my_circuit);
    // cout << importFromCSV("example", my_circuit);

    // my_circuit.setBranch(1, 2, {2, 4});
    // my_circuit.setBranch(1, 3, {1, 1});
    // my_circuit.setBranch(2, 4, {3, 4});
    // my_circuit.setBranch(3, 4, {1, 2});
    // my_circuit.setBranch(1, 1, {3, -4});
    // my_circuit.delVertex(8);
    // my_circuit.delEdge(-5,1);
    // my_circuit.setMark(8,0);
    // cout << my_circuit.isEdge(8,1);

    // cout << my_circuit.weight('dda', -5) << endl;
    
    my_circuit.printAdjList();

    // exportToCSV(my_circuit, "sss");
    // exportAdjListToCSV(my_circuit, "output");
    // printMatrix(my_circuit.getAdjMatrix(), my_circuit.n());
    // my_circuit.getAdjList();
    // string filename = "abc";
    // Complex ** matrix = my_circuit.getAdmitMatrix();
    // exportToCSV(&matrix, "fire");
    // Floyd(&my_circuit);
    // Floyd(&my_circuit);
    
    // my_circuit.setMark(2, 5);
    // cout << my_circuit.e() << endl;
    // my_circuit.printMark();
    // my_circuit.getAdjMatrix();
    // printMatrix(my_circuit.getAdjMatrix(), my_circuit.n());
    // my_circuit.printAdmitMatrix();

    // my_circuit.delVertex(2);
    // my_circuit.printAdjList();
    // cout << my_circuit.e() << endl;
    // my_circuit.getAdjMatrix();
    // printMatrix(my_circuit.getAdjMatrix(), my_circuit.n());
    // printMatrix(my_circuit.getAdjMatrix(), my_circuit.n());
    // my_circuit.printAdmitMatrix();



    // my_graph.printAdjList();
    // my_graph.printMark();
    // my_graph.setMark(2, 556);
    // my_graph.printMark();

    // // my_graph.addVertex(2);
    // my_circuit.delVertex(2);
    // my_circuit.printAdjList();
    // my_circuit.printAdmitMatrix();
    // my_graph.printMark();
    // cout << my_graph.n() << " " << my_graph.e();


    // int f = my_graph.first(1);
    // bool a = my_graph.isEdge(2, 3);
    // bool b = my_graph.isEdge(3, 2);
    // Complex w = my_graph.weight(2, 3);

    // int e = my_graph.e();
    // int n = my_graph.n();

    // cout << ": " << a << " " << b << " " << e << " " << n << " " << w << " " << f << endl;

    // my_graph.addVertex();
    // my_graph.delVertex();
    // cout << my_graph.n();
    // my_graph.delVertex();
    // cout << my_graph.next(1, 0);

    // my_graph.setMark(5, 5);
    // my_graph.setMark(1, 4);
    // my_graph.getMark(0);    


    

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

    // // vector<vector<Complex>> admitmatrix = my_graph.admitMatrix();
    // vector<vector<Complex>> adjmatrix = my_graph.adjMatrix();
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
    // Complex w = my_graph.weight(2, 3);

    // int e = my_graph.e();
    // int n = my_graph.n();

    // cout << ": " << a << " " << b << " " << e << " " << n << " " << w << " " << f;

    return 0;
}