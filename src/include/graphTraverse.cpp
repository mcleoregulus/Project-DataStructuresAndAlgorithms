
//为了确保访问所有顶点，可以在图G上调用graphTraverse

#include "graph.hpp"

void graphTraverse(Graph *G)
{
    int v;
    for (v = 0; v < G->n(); v++)
        G->setMark(v, UNVISITED); // Initialize mark bits
    for (v = 0; v < G->n(); v++)
        if (G->getMark(v) == UNVISITED)
            doTraverse(G, v);     //“doTraverse”函数可以通过使用本节中描述的图遍历方法之一来实现。
}