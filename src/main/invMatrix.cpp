#include <iostream>
#include <vector>
#include <complex>
#include <cmath>

using namespace std;

typedef complex<double> Complex;

const double EPS = 1e-9;

// 复数矩阵转置
vector<vector<Complex>> transpose(const vector<vector<Complex>>& a) {
    int n = a.size();
    vector<vector<Complex>> trans(n, vector<Complex>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            trans[i][j] = a[j][i];
        }
    }
    return trans;
}

// 复数矩阵相乘
vector<vector<Complex>> multiply(const vector<vector<Complex>>& a, const vector<vector<Complex>>& b) {
    int n = a.size();
    vector<vector<Complex>> result(n, vector<Complex>(n, 0.0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return result;
}

// 复数矩阵的LU分解求逆
vector<vector<Complex>> inverseMatrix(const vector<vector<Complex>>& a) {
    int n = a.size();
    vector<vector<Complex>> l(n, vector<Complex>(n, 0.0));
    vector<vector<Complex>> u(n, vector<Complex>(n, 0.0));

    // LU分解
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i <= j) {
                Complex sum = 0.0;
                for (int k = 0; k < i; k++) {
                    sum += l[i][k] * u[k][j];
                }
                u[i][j] = a[i][j] - sum;
            } else {
                Complex sum = 0.0;
                for (int k = 0; k < j; k++) {
                    sum += l[i][k] * u[k][j];
                }
                l[i][j] = (a[i][j] - sum) / u[j][j];
            }
        }
    }

    // 求L的逆
    vector<vector<Complex>> l_inv(n, vector<Complex>(n, 0.0));
    for (int i = 0; i < n; i++) {
        l_inv[i][i] = 1.0;
        for (int j = i - 1; j >= 0; j--) {
            Complex sum = 0.0;
            for (int k = j + 1; k < n; k++) {
                sum += l[i][k] * l_inv[k][j];
            }
            l_inv[i][j] = -sum / l[i][j];
        }
    }

    // 求U的逆
    vector<vector<Complex>> u_inv(n, vector<Complex>(n, 0.0));
    for (int i = n - 1; i >= 0; i--) {
        u_inv[i][i] = 1.0 / u[i][i];
        for (int j = i + 1; j < n; j++) {
            Complex sum = 0.0;
            for (int k = i; k < j; k++) {
                sum += u[i][k] * u_inv[k][j];
            }
            u_inv[i][j] = -sum / u[i][i];
        }
    }

    // 计算A的逆矩阵：A_inv = U_inv * L_inv
    vector<vector<Complex>> inv = multiply(u_inv, l_inv);

    return inv;
}

int main() {
    vector<vector<Complex>> matrix = {
        {complex<double>(1, 0), complex<double>(2, 0), complex<double>(3, 0)},
        {complex<double>(4, 0), complex<double>(5, 1), complex<double>(6, 0)},
        {complex<double>(7, 0), complex<double>(8, 0), complex<double>(10, 0)}
    };

    vector<vector<Complex>> inv = inverseMatrix(matrix);

    cout << "Inverse matrix:" << endl;
    for (int i = 0; i < inv.size(); i++) {
        for (int j = 0; j < inv.size(); j++) {
            cout << inv[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}