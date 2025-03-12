
#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <vector>
#include <complex>
#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>

#include "CircuitGraphm.hpp"
#include "CircuitGraphl.hpp"

using namespace std;


// void printMatrix(Complex** matrix) {
//     for (int i = 0; i < n; ++i) {
//         for (int j = 0; j < n; ++j) {
//             cout << matrix[i][j] << "\t";
//         }
//         cout << endl;
//     }
// }

// void printMatrix(vector<vector<Complex>> matrix)
// {
//     for (const auto &row : matrix)
//     {
//         for (const auto &num : row)
//         {
//             cout << num << "\t";
//         }
//         cout << endl;
//     }
//     cout << endl;
// };

void importFromMatrix(vector<vector<double>> &data, CircuitGraphm &circuit)
{
    int numVertex = 0;
    for (int i = 0; i < data.size(); ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            data[i][j] > numVertex ? numVertex = data[i][j] : numVertex = numVertex;
        }
    }

    while (circuit.n() < numVertex)
    {
        circuit.addVertex();
    }

    for (const auto &row : data)
    {
        Complex wgt = circuit.weight(row[0] - 1, row[1] - 1);
        if (wgt != Complex(0, 0))
        {
            Complex new_wgt = (wgt * Complex(row[2], row[3])) / (wgt + Complex(row[2], row[3]));
            circuit.setBranch(row[0], row[1], new_wgt);
        }
        else
        {
            circuit.setBranch(row[0], row[1], {row[2], row[3]});
        }
    }
}

int importFromCSV(const string &filename, CircuitGraphm &circuit)
{
    string filepath = "../../data/" + filename + ".csv";

    // 打开CSV文件
    ifstream file(filepath);
    if (!file.is_open())
    {
        cerr << "Cannot open file: " << filepath << endl;
        return 1;
    }

    string line;
    vector<vector<double>> data;

    // 跳过标题行
    if (file.good())
    {
        getline(file, line); // 读取并丢弃标题行
    }

    // 按行读取文件
    while (getline(file, line))
    {
        stringstream ss(line);
        string field;
        vector<string> fields;

        // 按逗号分割每行
        while (getline(ss, field, ','))
        {
            fields.push_back(field);
        }

        // 检查是否至少有三列数据
        if (fields.size() < 3)
        {
            // cerr << "Error: Invalid File1! " << endl;
            continue;
        }

        // 提取第一列中的数字对
        string firstColumn = fields[0];
        size_t dashPos = firstColumn.find('-');

        if (dashPos == string::npos)
        {
            // cerr << "Error: Invalid File! " << endl;
            continue;
        }

        string num1Str = firstColumn.substr(0, dashPos);
        string num2Str = firstColumn.substr(dashPos + 1);

        double num1, num2;
        try
        {
            num1 = stoi(num1Str);
            num2 = stoi(num2Str);
        }
        catch (const exception &e)
        {
            cerr << "Error: Invalid File, cannot convert to number! " << endl;
            continue;
        }

        // 提取第二列和第三列的数字
        double num3, num4;
        try
        {
            num3 = stod(fields[1]);
            num4 = stod(fields[2]);
        }
        catch (const exception &e)
        {
            cerr << "Error: Invalid File, cannot convert to number! " << endl;
            continue;
        }

        // 将提取的数字添加到二维vector中
        data.push_back({num1, num2, num3, num4});
    }

    // 关闭文件
    file.close();
    importFromMatrix(data, circuit);

    return 0;
}

#endif // UTILS_HPP