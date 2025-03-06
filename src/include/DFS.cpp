
#include "graph.hpp"

//这个实现包含了对PreVisit和PostVisit函数的调用。这些函数指定了在搜索过程中应该进行哪些活动。

void DFS(Graph *G, int v)
{ // Depth first search
    PreVisit(G, v);
    G->setMark(v, VISITED);
    // Take appropriate action
    for (int w = G->first(v); w < G->n(); w = G->next(v, w))
        if (G->getMark(w) == UNVISITED)
            DFS(G, w);      // 递归栈实现
    PostVisit(G, v);
    // Take appropriate action
}