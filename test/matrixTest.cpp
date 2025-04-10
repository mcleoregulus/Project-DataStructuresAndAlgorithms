#include <iostream>
#include "../../libs/eigen-3.4.0/Eigen/Dense"

using namespace Eigen;

int main() {
    Matrix3f A;
    A << 1, 2, 3,
         4, 5, 6,
         7, 8, 10;

    // 求逆矩阵
    Matrix3f A_inv = A.inverse();

    std::cout << "A:\n" << A << "\n";
    std::cout << "A_inv:\n" << A_inv << "\n";
    std::cout << A*A_inv << "\n";

    return 0;
}