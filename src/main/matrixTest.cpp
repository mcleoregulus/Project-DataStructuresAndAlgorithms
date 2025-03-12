
#include <iostream>
#include <complex>

int main() {
    const int n = 5; // 固定的数组大小
    std::complex<double> complexArray[n][n]; // 静态分配二维数组

    // 初始化二维数组
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            complexArray[i][j] = std::complex<double>(i + j, i - j); // 示例初始化
        }
    }

    // 输出二维数组
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << complexArray[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

// #include "../include/Graphl.hpp"
// #include <iostream>
// using namespace std;

// int main() {
//     // 定义并初始化一个 3x3 的二维数组
//     Complex arr[3][3] = {
//         {1, 2, 3},
//         {4, 5, 6},
//         {7, 8, {9,5}}
//     };

//     // 使用嵌套循环输出整个数组
//     for (int i = 0; i < 3; i++) { // 外层循环控制行
//         for (int j = 0; j < 3; j++) { // 内层循环控制列
//             cout << arr[i][j] << " ";
//         }
//         cout << endl; // 每行输出后换行
//     }

//     return 0;
// }