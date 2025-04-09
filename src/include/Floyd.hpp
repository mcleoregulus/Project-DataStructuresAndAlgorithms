#ifndef FLOYD_HPP
#define FLOYD_HPP

#include "Graph.hpp"
#include <iostream>

using namespace std;

// 全局变量（或类成员变量），用于存储路径信息
int **path;  // path[i][j] 存储 i 到 j 的最短路径的中间点
double **D;  // D[i][j] 存储 i 到 j 的最短距离

// 递归打印 i 到 j 的最短路径
void prn_pass(int i, int j) {
    if (path[i][j] != -1) {  // 如果有中间点
        prn_pass(i, path[i][j]);  // 递归打印 i 到中间点
        cout << path[i][j] << " -> ";  // 打印中间点
        prn_pass(path[i][j], j);  // 递归打印中间点到 j
    }
}

// 打印所有顶点对的最短路径
void print_allpaths(Graph *G) {
    cout << "\nFloyd Shortest Paths: \n";
    for (int i = 0; i < G->n(); i++) {
        for (int j = 0; j < G->n(); j++) {
            if (i != j && D[i][j] < INFINITY) {  // 排除自己到自己的情况，并检查可达性
                cout << "Path from " << i << " to " << j << ": ";
                cout << i << " -> ";
                prn_pass(i, j);
                cout << j << " (Impedance: " << D[i][j] << ")" << endl;
            }
        }
    }
}

// Floyd-Warshall 算法实现
void Floyd(Graph *G) {
    int n = G->n();

    // 动态分配 D 和 path 数组
    D = new double*[n];
    path = new int*[n];
    for (int i = 0; i < n; i++) {
        D[i] = new double[n];
        path[i] = new int[n];
    }

    // 初始化 D 和 path
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                D[i][j] = 0;  // 自己到自己的距离为 0
            } else {
                Complex w = G->weight(i, j);
                D[i][j] = (w != Complex(0, 0)) ? abs(w) : INFINITY;  // 如果边不存在，设为 INF
            }
            path[i][j] = -1;  // 初始时无中间点
        }
    }

    // Floyd-Warshall 核心算法
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (D[i][k] + D[k][j] < D[i][j]) {
                    D[i][j] = D[i][k] + D[k][j];
                    path[i][j] = k;  // 记录中间点
                }
            }
        }
    }

    // 打印所有最短路径
    print_allpaths(G);

    // 释放动态分配的内存
    for (int i = 0; i < n; i++) {
        delete[] D[i];
        delete[] path[i];
    }
    delete[] D;
    delete[] path;
}

// #include "Graph.hpp"

// void prn_pass(int i, int j)
// {
//     if (path[i][j] != -1)
//     {
//         prn_pass(i, path[i][j]);
//         Printout(path[i][j]);
//         prn_pass(path[i][j], j);
//     }
// }

// void print_allpaths()
// {
//     for (int i = 0; i < G->n(); i++)
//     {
//         for (int j = 0; j < G->n(); j++)
//         {
//             if (i != j)
//             {
//                 Printout(i);
//                 prn_pass(i, j);
//                 Printout(j);
//             }
//         }
//     }
// }

// void Floyd(Graph *G)
// {
//     int path[G->n()][G->n()];
//     double D[G->n()][G->n()];
//     for (int i = 0; i < G->n(); i++)
//     {
//         for (int j = 0; j < G->n(); j++)
//         {
//             D[i][j] = abs(G->weight(i, j));
//             path[i][j] = -1;
//         }
//         for (int k = 0; k < G->n(); k++)
//         {
//             for (int i = 0; i < G->n(); i++)
//             {
//                 for (int j = 0; j < G->n(); j++)
//                 {
//                     if (D[i][k] + D[k][j] < D[i][j])
//                     {
//                         D[i][j] = D[i][k] + D[k][j];
//                         path[i][j] = k;
//                     }
//                 }
//             }
//         }
//     }
//     print_allpaths();
// }

#endif // FLOYD_HPP