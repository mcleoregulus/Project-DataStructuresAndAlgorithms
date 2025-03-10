
#ifndef UTILS_HPP
#define UTILS_HPP

#include <vector>
#include <complex>
#include <iostream>

using namespace std;

void printMatrix(vector<vector<Complex>> matrix)
{
    for (const auto &row : matrix)
    {
        for (const auto &num : row)
        {
            cout << num << "\t";
        }
        cout << endl;
    }
    cout << endl;
};

#endif // UTILS_HPP