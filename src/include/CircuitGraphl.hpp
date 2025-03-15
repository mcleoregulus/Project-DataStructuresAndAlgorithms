
#ifndef CIRCUIT_GRAPHL_HPP
#define CIRCUIT_GRAPHL_HPP

#include "Graphl.hpp"
#include <iostream>
#include <cassert>
#include <complex>

using namespace std;

class CircuitGraphl : public Graphl {
    private:

    // int numNode;
    Complex ** admit_matrix;
    // vector<vector<Complex>> admit_matrix; // Use vector of vectors for admittance matrix


    public:

    CircuitGraphl(): Graphl() {}
    CircuitGraphl(int numVertx): Graphl(numVertx) {    // 显式调用Graphm构造函数

        // numNode = numVertx;
        // Initialize admittance matrix

    }

    ~CircuitGraphl() {}

    // Complex** getAdmitMatrix() {
    //     printAdjList();
    //     LList<LList<Edge> *> *const &adjList = getAdjList();
    //     adjList->moveToStart();


    //     return admit_matrix;
    // }


    // vector<vector<Complex>> getAdmitMatrix()
    // {
    //     admit_matrix.resize(n(), vector<Complex>(n(), Complex(0, 0)));

    //     for (int i = 0; i < n(); ++i)
    //     {
    //         Complex sum = 0; //  diagonal term
    //         for (int j = 0; j < n(); ++j)
    //         {
    //             if (getAdjMatrix()[i][j] == Complex {0, 0}) {continue;}
    //             sum += Complex (1) / getAdjMatrix()[i][j];
    //         }
    //         admit_matrix[i][i] = sum;
    //         for (int j = 0; j < n(); ++j) // off-diagonal term
    //         {
    //             if (i != j && getAdjMatrix()[i][j] != Complex {0, 0})
    //             {
    //                 admit_matrix[i][j] = Complex (-1) / getAdjMatrix()[i][j];
    //             }
    //         }
    //     }
    //     return admit_matrix;
    // }

    void setBranch(int node1, int node2, Complex impedance)
    {
        setEdge(node1-1, node2-1, impedance);
        setEdge(node2-1, node1-1, impedance);
    }

};


#endif // CIRCUIT_GRAPHL_HPP