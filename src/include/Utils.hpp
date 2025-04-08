
#ifndef UTILS_HPP
#define UTILS_HPP

const int MAX_SIZE = 1000;

#include <iostream>
#include <iomanip>
#include <complex>
#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>
// #include "CircuitGraphm.hpp"
#include "Graphl.hpp"

using namespace std;

void printMatrix(Complex **matrix, int size)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

void importFromMatrix(double **&data, Graphl &circuit, int numBranch)
{
    for (int i = 0; i < numBranch; ++i)
    {
        if (circuit.n() < data[i][0] || circuit.n() < data[i][1])
        {
            circuit.setBranch(data[i][0], data[i][1], {data[i][2], data[i][3]});
        }
        else
        {
            Complex wgt = circuit.weight(data[i][0] - 1, data[i][1] - 1);
            if (wgt != Complex(0, 0))
            {
                Complex new_wgt = (wgt * Complex(data[i][2], data[i][3])) / (wgt + Complex(data[i][2], data[i][3]));
                circuit.setBranch(data[i][0], data[i][1], new_wgt);
            }
            else
            {
                circuit.setBranch(data[i][0], data[i][1], {data[i][2], data[i][3]});
            }
        }
    }
}

int importFromCSV(const string &filename, Graphl &circuit)
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
    int numBranch = 0;
    double **data = new double *[MAX_SIZE];

    // 跳过标题行
    if (file.good())
    {
        getline(file, line); // 读取并丢弃标题行
    }

    // 按行读取文件
    while (getline(file, line) && numBranch < MAX_SIZE)
    {
        stringstream ss(line);
        string field;
        string fields[3]; // 只需要存储前三列
        int col = 0;

        // 按逗号分割每行，只读取前三列
        while (getline(ss, field, ',') && col < 3)
        {
            fields[col++] = field;
        }

        // 检查是否至少有三列数据
        if (col < 3)
        {
            continue;
        }

        // 提取第一列中的数字对
        string firstColumn = fields[0];
        size_t dashPos = firstColumn.find('-');

        if (dashPos == string::npos)
        {
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

        // 存储数据
        data[numBranch] = new double[4];
        data[numBranch][0] = num1;
        data[numBranch][1] = num2;
        data[numBranch][2] = num3;
        data[numBranch][3] = num4;
        numBranch++;
    }

    file.close();
    importFromMatrix(data, circuit, numBranch);

    // 释放内存
    for (int i = 0; i < numBranch; i++)
    {
        delete[] data[i];
    }
    delete[] data;

    return 0;
}

// void exportToCSV(Graphl &circuit, const string &filename)
// {
//     string filepath = "../../data/" + filename + ".csv";
//     ofstream file(filepath);

//     if (!file.is_open())
//     {
//         cerr << "Cannot open file for writing: " << filepath << endl;
//         return;
//     }

//     file << "Line bus to bus,R (resistance),X (reactance)\n";

//     Complex **matrix = circuit.getAdmitMatrix();
//     for (int i = 0; i < circuit.n(); ++i)
//     {
//         for (int j = i + 1; j < circuit.n(); ++j) // 避免重复边，只输出一次
//         {
//             if (matrix[i][j] != complex<double>(0, 0))
//             {
//                 file << "\"" << i + 1 << "-" << j + 1 << "\","
//                      << fixed << setprecision(4) << matrix[i][j].real() << ","
//                      << matrix[i][j].imag() << "\n";
//             }
//         }
//     }

//     file.close();
//     cout << "Exported graph to " << filepath << endl;
// }
void exportAdjListToCSV(Graphl &circuit, const std::string &filename)
{
    std::string filepath = "../../data/" + filename + ".csv";
    std::ofstream file(filepath);

    if (!file.is_open())
    {
        std::cerr << "Cannot open file for writing: " << filepath << std::endl;
        return;
    }

    file << "Line bus to bus,R (resistance),X (reactance)\n";

    // 获取邻接表，每个顶点对应一个 LList<Edge>*，存储所有邻接边
    LList<LList<Edge> *> *adjList = circuit.getAdjList();

    // 遍历所有顶点
    for (int i = 0; i < circuit.n(); ++i)
    {
        // 移动到相应的顶点 i 位置，获取其邻接链表
        adjList->moveToPos(i);
        LList<Edge> *currEdges = adjList->getValue();

        // 遍历顶点 i 的所有边
        currEdges->moveToStart();
        while (currEdges->currPos() < currEdges->length())
        {
            Edge e = currEdges->getValue();
            int j = e.vertex(); // 边连接到的顶点编号（0-based）

            // 为了防止重复输出无向边，只在 i < j 时输出
            if (i < j && e.weight() != Complex(0, 0))
            {
                file << i + 1 << "-" << j + 1 << ","
                     << std::fixed << std::setprecision(4) << e.weight().real() << ","
                     << e.weight().imag() << "\n";
            }
            currEdges->next();
        }
    }

    file.close();
    std::cout << "Exported graph to " << filepath << std::endl;
}

#endif // UTILS_HPP