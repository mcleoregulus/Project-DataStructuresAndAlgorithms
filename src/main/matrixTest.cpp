

#include "../include/Graphl.hpp"
#include <iostream>
using namespace std;

int main() {
    // 定义并初始化一个 3x3 的二维数组
    Complex arr[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, {9,5}}
    };

    // 使用嵌套循环输出整个数组
    for (int i = 0; i < 3; i++) { // 外层循环控制行
        for (int j = 0; j < 3; j++) { // 内层循环控制列
            cout << arr[i][j] << " ";
        }
        cout << endl; // 每行输出后换行
    }

    return 0;
}