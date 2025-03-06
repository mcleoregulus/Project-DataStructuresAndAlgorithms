
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

    vector<vector<complex<double>>> admit_matrix; // Use vector of vectors for admittance matrix


    public:

    CircuitGraph(int numNode): Graphm(numNode) {    // 显式调用Graphm构造函数

        // Initialize admittance matrix
        admit_matrix.resize(numNode, vector<complex<double>>(numNode, complex<double>(0, 0)));

    }

    ~CircuitGraph() {}

    vector<vector<complex<double>>> admitMatrix()
    {
        admit_matrix.resize(n(), vector<complex<double>>(n(), complex<double>(0, 0)));

        for (int i = 0; i < n(); ++i)
        {
            complex<double> sum = 0; //  diagonal term
            for (int j = 0; j < n(); ++j)
            {
                sum += adjMatrix()[i][j];
            }
            admit_matrix[i][i] = sum;
            for (int j = 0; j < n(); ++j) // off-diagonal term
            {
                if (i != j)
                {
                    admit_matrix[i][j] = -adjMatrix()[i][j];
                }
            }
        }
        return admit_matrix;
    }


};


#endif // CIRCUIT_GRAPH_HPP