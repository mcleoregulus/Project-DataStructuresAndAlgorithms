#ifndef GRAPHL2_HPP
#define GRAPHL2_HPP

#include "graph.hpp"
#include "LList.hpp"

// class Edge
// {
//     int vert;
//     Complex wt;

// public:
//     Edge()
//     {
//         vert = -1;
//         wt = -1;
//     }
//     Edge(int v, Complex w)
//     {
//         vert = v;
//         wt = w;
//     }
//     int vertex() { return vert; }
//     Complex weight() { return wt; }
// };

class Edge
{
    int vert;
    int wt;

public:
    Edge()
    {
        vert = -1;
        wt = -1;
    }
    Edge(int v, int w)
    {
        vert = v;
        wt = w;
    }
    int vertex() { return vert; }
    int weight() { return wt; }
};

class Graphl
{
private:
    LList<LList<Edge>> vertex; // 邻接表，每个元素是一个LList<Edge>，表示一个顶点的出边列表
    int numVertex, numEdge;
    int *mark;

    // 辅助函数：获取顶点v的出边列表
    LList<Edge> &getVertexList(int v)
    {
        LList<Edge> *temp = nullptr;
        vertex.moveToStart();
        for (int i = 0; i < v; i++)
        {
            vertex.next();
        }
        return vertex.getValue();
    }

public:
    Graphl(int numVert)
    {
        Init(numVert);
    }

    ~Graphl()
    {
        delete[] mark;  // 释放标记数组
        vertex.clear(); // 清空邻接表
    }

    void Init(int n)
    {
        numVertex = n;
        numEdge = 0;
        mark = new int[n]; // 初始化标记数组
        for (int i = 0; i < numVertex; i++)
        {
            mark[i] = UNVISITED;
        }
        vertex.clear(); // 清空邻接表
        for (int i = 0; i < numVertex; i++)
        {
            vertex.append(LList<Edge>()); // 为每个顶点初始化一个空的边列表
        }
    }

    int n() { return numVertex; } // 顶点数
    int e() { return numEdge; }   // 边数

    int first(int v)
    {
        LList<Edge> &list = getVertexList(v);
        if (list.length() == 0)
        {
            return numVertex; // 无邻居
        }
        list.moveToStart(); // 移动到链表头
        Edge it = list.getValue();
        return it.vertex();
    }

    int next(int v, int w)
    {
        LList<Edge> &list = getVertexList(v);
        if (list.currPos() + 1 < list.length())
        {
            list.next(); // 移动到下一个位置
            Edge it = list.getValue();
            return it.vertex();
        }
        return numVertex; // 无更多邻居
    }

    // void setEdge(int i, int j, int weight)
    // {
    //     // assert(weight > 0 && "May not set weight to 0");
    //     Edge currEdge(j, weight);
    //     LList<Edge> &list = getVertexList(i);

    //     bool found = false;
    //     list.moveToStart();
    //     while (list.currPos() < list.length())
    //     {
    //         Edge temp = list.getValue();
    //         if (temp.vertex() == j)
    //         {
    //             found = true;
    //             break;
    //         }
    //         list.next();
    //     }

    //     if (found)
    //     {                          // 边已存在
    //         list.remove();         // 删除旧边
    //         list.insert(currEdge); // 插入新边
    //     }
    //     else
    //     { // 插入新边并保持顺序
    //         numEdge++;
    //         list.moveToStart();
    //         while (list.currPos() < list.length())
    //         {
    //             Edge temp = list.getValue();
    //             if (temp.vertex() > j)
    //                 break;
    //             list.next();
    //         }
    //         list.insert(currEdge);
    //     }
    // }

    void setEdge(int i, int j, int weight) {
        assert(weight > 0 && "May not set weight to 0");
        Edge currEdge(j, weight);
        LList<Edge>& list = getVertexList(i);
    
        bool found = false;
        list.moveToStart();
        while (list.currPos() < list.length()) {
            Edge temp = list.getValue();
            if (temp.vertex() == j) {
                found = true;
                break;
            }
            list.next();
        }
    
        if (found) { // 边已存在
            list.remove(); // 删除旧边
            list.insert(currEdge); // 插入新边
        } else { // 插入新边并保持顺序
            numEdge++;
            list.moveToStart();
            while (list.currPos() < list.length()) {
                Edge temp = list.getValue();
                if (temp.vertex() > j) break;
                list.next();
            }
            list.insert(currEdge);
        }
    }

    void delEdge(int i, int j)
    {
        LList<Edge> &list = getVertexList(i);
        bool found = false;
        list.moveToStart();
        while (list.currPos() < list.length())
        {
            Edge temp = list.getValue();
            if (temp.vertex() == j)
            {
                found = true;
                break;
            }
            list.next();
        }
        if (found)
        {
            list.remove(); // 删除边
            numEdge--;
        }
    }

    bool isEdge(int i, int j)
    {
        LList<Edge> &list = getVertexList(i);
        list.moveToStart();
        while (list.currPos() < list.length())
        {
            Edge temp = list.getValue();
            if (temp.vertex() == j)
                return true;
            list.next();
        }
        return false;
    }

    int weight(int i, int j)
    {
        if (isEdge(i, j))
        {
            LList<Edge> &list = getVertexList(i);
            Edge curr = list.getValue();
            return curr.weight();
        }
        else
        {
            return 0;
        }
    }

    int getMark(int v) { return mark[v]; }
    void setMark(int v, int val) { mark[v] = val; }
};

#endif // GRAPHL2_HPP