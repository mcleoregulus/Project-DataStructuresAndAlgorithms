

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <stdexcept>

#include "../include/CircuitGraph.hpp"

using namespace std;

int main() {
    string filename = "example";
    string filepath = "../../data/" + filename + ".csv";

    // 打开CSV文件
    ifstream file(filepath);
    if (!file.is_open()) {
        cerr << "Cannot open file: " << filepath << endl;
        return 1;
    }

    string line;
    vector<vector<double>> data;

    // 跳过标题行
    if (file.good()) {
        getline(file, line); // 读取并丢弃标题行
    }

    // 按行读取文件
    while (getline(file, line)) {
        stringstream ss(line);
        string field;
        vector<string> fields;

        // 按逗号分割每行
        while (getline(ss, field, ',')) {
            fields.push_back(field);
        }

        // 检查是否至少有三列数据
        if (fields.size() < 3) {
            // cerr << "Error: Invalid File1! " << endl;
            continue;
        }

        // 提取第一列中的数字对
        string firstColumn = fields[0];
        size_t dashPos = firstColumn.find('-');

        if (dashPos == string::npos) {
            // cerr << "Error: Invalid File! " << endl;
            continue;
        }

        string num1Str = firstColumn.substr(0, dashPos);
        string num2Str = firstColumn.substr(dashPos + 1);

        double num1, num2;
        try {
            num1 = stoi(num1Str);
            num2 = stoi(num2Str);
        } catch (const exception& e) {
            cerr << "Error: Invalid File, cannot convert to number! " << endl;
            continue;
        }

        // 提取第二列和第三列的数字
        double num3, num4;
        try {
            num3 = stod(fields[1]);
            num4 = stod(fields[2]);
        } catch (const exception& e) {
            cerr << "Error: Invalid File, cannot convert to number! " << endl;
            continue;
        }

        // 将提取的数字添加到二维vector中
        data.push_back({num1, num2, num3, num4});
    }

    // 关闭文件
    file.close();


    int numVertex = 0;
    for (int i = 0; i < data.size(); ++i) {
        for (int j = 0; j < 2; ++j) {
            cout << data[i][j] << " ";
            data[i][j] > numVertex ? numVertex = data[i][j] : numVertex = numVertex;
        }
        cout << endl;
    }

    cout << endl << numVertex;

    CircuitGraph circuit(numVertex);




    return 0;
}
