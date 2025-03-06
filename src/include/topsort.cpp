
#include "graph.hpp"
#include "queue.hpp"

void topsort(Graph *G)
{ // Topological sort: recursive
    int i;
    for (i = 0; i < G->n(); i++) // Initialize Mark array
        G->setMark(i, UNVISITED);
    for (i = 0; i < G->n(); i++) // Process all vertices
        if (G->getMark(i) == UNVISITED)
            tophelp(G, i);
    // Call recursive helper function
}
void tophelp(Graph *G, int v)
{ // Process vertex v
    G->setMark(v, VISITED);
    for (int w = G->first(v); w < G->n(); w = G->next(v, w))
        if (G->getMark(w) == UNVISITED)
            tophelp(G, w);
    printout(v);
    // PostVisit for Vertex v
}

// Topological sort: Queue
void topsort(Graph *G, Queue<int> *Q)
{
    int Count[G->n()];
    int v, w;
    for (v = 0; v < G->n(); v++)
        Count[v] = 0;            // Initialize
    for (v = 0; v < G->n(); v++) // Process every edge
        for (w = G->first(v); w < G->n(); w = G->next(v, w))
            Count[w]++;
    // Add to v2’s prereq count
    for (v = 0; v < G->n(); v++) // Initialize queue
        if (Count[v] == 0)
            // Vertex has no prerequisites
            Q->enqueue(v);
    while (Q->length() != 0)
    { // Process the vertices
        v = Q->dequeue();
        printout(v);
        // PreVisit for "v"
        for (w = G->first(v); w < G->n(); w = G->next(v, w))
        {
            Count[w]--;
            // One less prerequisite
            if (Count[w] == 0)
                Q->enqueue(w);
        }
    }
}