
#ifndef UTILS_HPP
#define UTILS_HPP

#include <vector>
#include <complex>
#include <iostream>

using namespace std;

void printMatrix(vector<vector<complex<double>>> matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix.size(); j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
};


#endif  // UTILS_HPP