
#include <iostream>
#include "../include/CircuitGraph.hpp"
#include "../include/Utils.hpp"
// #include "../include/Dijkstra.hpp"


using namespace std;

int main() {
    CircuitGraph my_circuit(4);
    // printMatrix(my_circuit.adjMatrix());
    // printMatrix(my_circuit.admitMatrix());

    my_circuit.setBranch(1, 2, {2, 4});
    my_circuit.setBranch(1, 3, {1, 1});
    my_circuit.setBranch(2, 4, {3, 4});
    my_circuit.setBranch(3, 4, {1, 2});

    printMatrix(my_circuit.adjMatrix());
    printMatrix(my_circuit.admitMatrix());

    // vector<complex<double>> D;
    // Dijkstra(my_circuit.adjMatrix(), D, 1);
    // cout << D[0];

    // my_circuit.delVertex(2);
    // printMatrix(my_circuit.adjMatrix());
    // printMatrix(my_circuit.admitMatrix());
    // cout << my_circuit.n();


    // int f = my_graph.first(1);
    // bool a = my_graph.isEdge(2, 3);
    // bool b = my_graph.isEdge(3, 2);
    // complex<double> w = my_graph.weight(2, 3);

    // int e = my_graph.e();
    // int n = my_graph.n();

    // cout << ": " << a << " " << b << " " << e << " " << n << " " << w << " " << f;

    return 0;
}
