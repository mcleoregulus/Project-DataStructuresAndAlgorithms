
#ifndef CIRCUIT_GRAPH_HPP
#define CIRCUIT_GRAPH_HPP

#include "Graphm.hpp"
#include <iostream>
#include <cassert>
#include <complex>
#include <vector>

using namespace std;

class CircuitGraph : public Graphm {
    private:

    vector<vector<Complex>> admit_matrix; // Use vector of vectors for admittance matrix


    public:

    CircuitGraph(int numNode): Graphm(numNode) {    // 显式调用Graphm构造函数

        // Initialize admittance matrix
        admit_matrix.resize(numNode, vector<Complex>(numNode, Complex(0, 0)));

    }

    ~CircuitGraph() {}

    vector<vector<Complex>> getAdmitMatrix()
    {
        admit_matrix.resize(n(), vector<Complex>(n(), Complex(0, 0)));

        for (int i = 0; i < n(); ++i)
        {
            Complex sum = 0; //  diagonal term
            for (int j = 0; j < n(); ++j)
            {
                if (getAdjMatrix()[i][j] == Complex {0, 0}) {continue;}
                sum += Complex (1) / getAdjMatrix()[i][j];
            }
            admit_matrix[i][i] = sum;
            for (int j = 0; j < n(); ++j) // off-diagonal term
            {
                if (i != j && getAdjMatrix()[i][j] != Complex {0, 0})
                {
                    admit_matrix[i][j] = Complex (-1) / getAdjMatrix()[i][j];
                }
            }
        }
        return admit_matrix;
    }

    void setBranch(int node1, int node2, Complex impedance)
    {
        setEdge(node1-1, node2-1, impedance);
        setEdge(node2-1, node1-1, impedance);
    }

};


#endif // CIRCUIT_GRAPH_HPP