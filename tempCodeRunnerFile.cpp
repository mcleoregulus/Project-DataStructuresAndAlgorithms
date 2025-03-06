#include <iostream>
// #include <vector>
// #include <complex>

// using namespace std;

// void printMatrix(const vector<vector<complex<double>>>& matrix) {
//     for (const auto& row : matrix) {
//         for (const auto& elem : row) {
//             cout << elem << " ";
//         }
//         cout << endl;
//     }
// }

// vector<vector<complex<double>>> removeCross(vector<vector<complex<double>>>& matrix, int rowToRemove, int colToRemove) {
//     // 删除指定行
//     if (rowToRemove >= 0 && rowToRemove < matrix.size()) {
//         matrix.erase(matrix.begin() + rowToRemove);
//     }

//     // 删除指定列
//     for (auto& row : matrix) {
//         if (colToRemove >= 0 && colToRemove < row.size()) {
//             row.erase(row.begin() + colToRemove);
//         }
//     }

//     return matrix;
// }

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
//     printMatrix(matrix);

//     // 删除第1行和第1列 (0-based index)
//     int rowToDelete = 1;
//     int colToDelete = 1;

//     removeCross(matrix, rowToDelete, colToDelete);

//     // 打印调整后的矩阵
//     cout << "\nMatrix after removing row " << rowToDelete << " and column " << colToDelete << ":" << endl;
//     printMatrix(matrix);

//     return 0;
// }