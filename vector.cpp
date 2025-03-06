// #include <iostream>
// #include <vector>
// #include <complex>

// using namespace std;

// int main() {
//     // 创建一个3x4的二维数组，初始值为0
//     int n = 5;
//     vector<vector<complex<double>>> matrix(n, vector<complex<double>>(n, 0));

//     // 打印二维数组
//     for (size_t i = 0; i < matrix.size(); ++i) {
//         for (size_t j = 0; j < matrix[i].size(); ++j) {
//             cout << matrix[i][j] << " ";
//         }
//         cout << endl;
//     }

//     return 0;
// }


// #include <iostream>
// #include <vector>
// #include <complex>

// using namespace std;

// int main() {
//     int n = 3; // 初始大小
//     vector<vector<complex<double>>> matrix(n, vector<complex<double>>(n, complex<double>(0, 0)));

//     // 填充初始矩阵
//     for (int i = 0; i < n; ++i) {
//         for (int j = 0; j < n; ++j) {
//             matrix[i][j] = complex<double>(i + j, i * j);
//         }
//     }

//     // 打印初始矩阵
//     cout << "Initial matrix (" << n << "x" << n << "):" << endl;
//     for (const auto& row : matrix) {
//         for (const auto& elem : row) {
//             cout << elem << " ";
//         }
//         cout << endl;
//     }

//     // 调整大小为 (n+1)x(n+1)
//     matrix.resize(n + 1); // 调整行数
//     for (auto& row : matrix) {
//         row.resize(n + 1, complex<double>(0, 0)); // 调整列数
//     }

//     // 初始化新增的行和列
//     // for (int i = 0; i < n + 1; ++i) {
//     //     for (int j = 0; j < n + 1; ++j) {
//     //         if (i >= n || j >= n) {
//     //             matrix[i][j] = complex<double>(i + j, i * j); // 示例初始化
//     //         }
//     //     }
//     // }

//     // 打印调整后的矩阵
//     cout << "\nResized matrix (" << n + 1 << "x" << n + 1 << "):" << endl;
//     for (const auto& row : matrix) {
//         for (const auto& elem : row) {
//             cout << elem << " ";
//         }
//         cout << endl;
//     }

//     return 0;
// }

#include <iostream>
#include <vector>
#include <complex>

using namespace std;

void printMatrix(const vector<vector<complex<double>>>& matrix) {
    for (const auto& row : matrix) {
        for (const auto& elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
}

vector<vector<complex<double>>> removeCross(vector<vector<complex<double>>>& matrix, int rowToRemove, int colToRemove) {
    // 删除指定行
    if (rowToRemove >= 0 && rowToRemove < matrix.size()) {
        matrix.erase(matrix.begin() + rowToRemove);
    }

    // 删除指定列
    for (auto& row : matrix) {
        if (colToRemove >= 0 && colToRemove < row.size()) {
            row.erase(row.begin() + colToRemove);
        }
    }

    return matrix;
}

int main() {
    int n = 3; // 初始大小
    vector<vector<complex<double>>> matrix(n, vector<complex<double>>(n, complex<double>(0, 0)));

    // 填充初始矩阵
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = complex<double>(i + j, i * j);
        }
    }

    // 打印初始矩阵
    cout << "Initial matrix (" << n << "x" << n << "):" << endl;
    printMatrix(matrix);

    // 删除第1行和第1列 (0-based index)
    int rowToDelete = 1;
    int colToDelete = 1;

    removeCross(matrix, rowToDelete, colToDelete);

    // 打印调整后的矩阵
    cout << "\nMatrix after removing row " << rowToDelete << " and column " << colToDelete << ":" << endl;
    printMatrix(matrix);

    return 0;
}