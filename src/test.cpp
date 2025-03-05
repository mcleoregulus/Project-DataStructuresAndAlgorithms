
#include <iostream>
#include "../include/Graphm.cpp"
// #include "Djsktra.cpp"

using namespace std;

int main() {

    Graphm my_graph(5);
    my_graph.setEdge(2, 3, 50);

    bool a = my_graph.isEdge(2, 3);
    bool b = my_graph.isEdge(3, 2);
    int w = my_graph.weight(2, 3);

    int e = my_graph.e();
    int n = my_graph.n();

    cout << ": " << a << " " << b << " " << e << " " << n << " " << w;




    return 0;
}
