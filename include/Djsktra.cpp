
#include "graph.hpp"

// Compute shortest path distances from "s".
// Return these distances in "D".
void Dijkstra(Graph *G, int *D, int s)
{
    int i, v, w;
    for (i = 0; i < G->n(); i++)
    {
        v = minVertex(G, D);
        // Process the vertices
        if (D[v] == 1e27) // INFINITE
            return;       // Unreachable vertices
        G->setMark(v, 1); // VISITED
        for (w = G->first(v); w < G->n(); w = G->next(v, w))
            if (D[w] > (D[v] + G->weight(v, w)))
                D[w] = D[v] + G->weight(v, w);
    }
}

int minVertex(Graph *G, int *D) // 密集图
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