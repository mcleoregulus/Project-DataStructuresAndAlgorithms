
#include <iostream>
#include "../include/Graphm.cpp"
// #include "Djsktra.cpp"

using namespace std;

int main() {

    Graphm my_graph(5);
    my_graph.setEdge(0, 1, 1);
    my_graph.setEdge(0, 2, 1);
    my_graph.setEdge(1, 2, 5);
    my_graph.setEdge(1, 3, 1);
    my_graph.setEdge(2, 3, 1);

    my_graph.setEdge(1, 0, 1);
    my_graph.setEdge(2, 0, 1);
    my_graph.setEdge(2, 1, 5);
    my_graph.setEdge(3, 1, 1);
    my_graph.setEdge(3, 2, 1);

    bool a = my_graph.isEdge(2, 3);
    bool b = my_graph.isEdge(3, 2);
    int w = my_graph.weight(2, 3);

    int e = my_graph.e();
    int n = my_graph.n();
    int **adjmatrix = my_graph.getMatrix();
    int **admitmatrix =my_graph.admitMatrix();

    // cout << ": " << a << " " << b << " " << e << " " << n << " " << w;
    for (int i = 0; i < my_graph.n(); i++) {
        for (int j = 0; j < my_graph.n(); j++) {
            cout << admitmatrix[i][j] << "\t";
        }
        cout << endl;
    }

    // for (int i = 0; i < 4; ++i) {    //释放内存？
    //     delete[] admitmatrix[i];
    // }
    // delete[] admitmatrix;



    return 0;
}
