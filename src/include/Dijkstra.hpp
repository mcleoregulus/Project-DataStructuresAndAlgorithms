
#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP

#include <vector>
#include <complex>
#include <limits>
#include <cmath>

#include <queue>
#include <unordered_map>

using namespace std;

// 定义一个大值，用于表示无穷大
// const complex<double> INFINITY_COMPLEX = complex<double>(numeric_limits<double>::infinity(), 0);

// // 比较两个复数的模
// bool compareByModulus(const complex<double> &a, const complex<double> &b)
// {
//     return abs(a) < abs(b);
// }

// // 假设邻接矩阵是一个二维的 vector<complex<double>> 数组
// void Dijkstra(const vector<vector<complex<double>>> &adjMatrix, vector<complex<double>> &D, int s)
// {
//     int n = adjMatrix.size();
//     vector<bool> visited(n, false); // 用于标记顶点是否已被访问         改用Graph的mark

//     // 初始化距离数组
//     for (int i = 0; i < n; i++)
//     {
//         D[i] = INFINITY_COMPLEX;
//     }
//     D[s] = complex<double>(0, 0); // 起点到自身的距离为 0

//     // 迪杰斯特拉算法主循环
//     for (int i = 0; i < n; i++)
//     {
//         // 找到当前距离最小的顶点
//         int v = -1;
//         complex<double> minDist = INFINITY_COMPLEX;
//         for (int j = 0; j < n; j++)
//         {
//             if (!visited[j] && compareByModulus(D[j], minDist))
//             {
//                 minDist = D[j];
//                 v = j;
//             }
//         }

//         // 如果所有顶点都已访问，或者当前顶点不可达，退出循环
//         if (v == -1)
//         {
//             break;
//         }

//         // 标记当前顶点为已访问
//         visited[v] = true;

//         // 更新当前顶点的邻接顶点的距离
//         for (int w = 0; w < n; w++)
//         {
//             if (adjMatrix[v][w] != complex<double>(0, 0) && !visited[w])
//             { // 如果有边且顶点未被访问
//                 complex<double> newDist = D[v] + adjMatrix[v][w];
//                 if (compareByModulus(newDist, D[w]))
//                 { // 更新距离
//                     D[w] = newDist;
//                 }
//             }
//         }
//     }
// }

#include "graph.hpp"

// Compute shortest path distances from "s".
// Return these distances in "D".
void Dijkstra(Graph *G, double *D, int s)
{
    int i, v;
    complex<double> w;
    for (i = 0; i < G->n(); i++)
    {
        v = minVertex(G, D);
        // Process the vertices
        if (D[v] == INFINITY) // INFINITE
            return;       // Unreachable vertices
        G->setMark(v, 1); // VISITED
        for (w = G->first(v); abs(w) < G->n(); w = G->next(v, w))
            if (D[w] > (D[v] + G->weight(v, w)))
                D[w] = D[v] + G->weight(v, w);
    }
}

int minVertex(Graph *G, double *D) // 密集图
{                               // Find min cost vertex
    int i, v = -1;
    // Initialize v to some unvisited vertex
    for (i = 0; i < G->n(); i++)
        if (G->getMark(i) == 0) // UNVISITED
        {
            v = i;
            break;
        }
    for (i++; i < G->n(); i++)                     // Now find smallest D value
        if ((G->getMark(i) == 0) && (D[i] < D[v])) // UNVISITED
            v = i;
    return v;
}



// // Dijkstra算法计算最短路径
// void shortestPath(const string &start, const string &end)
// {
//     if (adjList.find(start) == adjList.end() || adjList.find(end) == adjList.end())
//     {
//         cerr << "错误：起点或终点不存在！\n";
//         return;
//     }

//     // 初始化距离和前驱节点
//     unordered_map<string, int> dist;
//     unordered_map<string, string> prev;
//     for (const auto &node : adjList)
//     {
//         dist[node.first] = INT_MAX;
//     }
//     dist[start] = 0;

//     // 优先队列：按距离排序（最小堆）
//     using Pair = pair<int, string>;
//     priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
//     pq.push({0, start});

//     while (!pq.empty())
//     {
//         string u = pq.top().second;
//         int currentDist = pq.top().first;
//         pq.pop();

//         if (currentDist > dist[u])
//             continue; // 跳过旧记录

//         for (const Edge &edge : adjList[u])
//         {
//             string v = edge.dest;
//             int newDist = currentDist + edge.weight;
//             if (newDist < dist[v])
//             {
//                 dist[v] = newDist;
//                 prev[v] = u;
//                 pq.push({newDist, v});
//             }
//         }
//     }

//     // 输出结果
//     if (dist[end] == INT_MAX)
//     {
//         cout << "节点 " << start << " 到 " << end << " 不可达。\n";
//         return;
//     }

//     vector<string> path;
//     for (string at = end; at != start; at = prev[at])
//     {
//         path.push_back(at);
//         if (prev.find(at) == prev.end())
//         {
//             cerr << "路径回溯失败！\n";
//             return;
//         }
//     }
//     path.push_back(start);
//     reverse(path.begin(), path.end());

//     cout << "最短路径总长度: " << dist[end] << "\n路径: ";
//     for (size_t i = 0; i < path.size(); ++i)
//     {
//         cout << path[i];
//         if (i != path.size() - 1)
//             cout << " -> ";
//     }
//     cout << "\n";
// }

#endif // DIJKSTRA_HPP