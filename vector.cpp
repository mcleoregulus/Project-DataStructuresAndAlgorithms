#include <iostream>
#include <vector>
#include <complex>

using namespace std;

int main() {
    // 创建一个3x4的二维数组，初始值为0
    int n = 5;
    vector<vector<complex<double>>> matrix(n, vector<complex<double>>(n, 0));

    // 打印二维数组
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}