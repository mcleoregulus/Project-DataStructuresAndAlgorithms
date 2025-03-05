
#include <iostream>
#include "../include/Graphm.cpp"
// #include "Djsktra.cpp"

using namespace std;

int main() {

    Graphm my_graph(4);     //无向图，电力系统分析 part2 tab2
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

    complex<double> **admitmatrix =my_graph.admitMatrix();
    my_graph.printMatrix(admitmatrix);


    // int f = my_graph.first(1);
    // bool a = my_graph.isEdge(2, 3);
    // bool b = my_graph.isEdge(3, 2);
    // complex<double> w = my_graph.weight(2, 3);

    // int e = my_graph.e();
    // int n = my_graph.n();
    // int **adjmatrix = my_graph.adjMatrix();

    // cout << ": " << a << " " << b << " " << e << " " << n << " " << w << " " << f;

    return 0;
}
