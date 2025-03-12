
#ifndef CIRCUIT_GRAPHL_HPP
#define CIRCUIT_GRAPHL_HPP

#include "Graphl.hpp"
#include <iostream>
#include <cassert>
#include <complex>
#include <vector>

using namespace std;

class CircuitGraphl : public Graphl
{
private:
    Complex **admit_matrix;

public:
    CircuitGraphl(int numNode) : Graphl(numNode) // 显式调用Graphm构造函数
    {
        // const int n = numNode;
        // 动态分配二维数组
        admit_matrix = new Complex *[numNode];
        for (int i = 0; i < numNode; ++i)
            admit_matrix[i] = new Complex[numNode];
    }

    ~CircuitGraphl()
    {
        for (int i = 0; i < n(); ++i)
        {
            delete[] admit_matrix[i];
        }
        delete[] admit_matrix;
    }

    Complex **getAdmitMatrix()
    {
        for (int i = 0; i < n(); ++i) {
            cout << getAdjList()[i]->length();
            // cout << getAdjList()[i]->getValue().weight();
        }




        return admit_matrix;
    }

    void printAdmitMatrix()
    {
        for (int i = 0; i < n(); ++i)
        {
            for (int j = 0; j < n(); ++j)
            {
                cout << getAdmitMatrix()[i][j] << "\t";
            }
            cout << endl;
        }
    }

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
        setEdge(node1 - 1, node2 - 1, impedance);
        setEdge(node2 - 1, node1 - 1, impedance);
    }
};

#endif // CIRCUIT_GRAPHL_HPP