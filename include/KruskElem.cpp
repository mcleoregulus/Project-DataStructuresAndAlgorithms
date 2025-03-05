
#include "graph.hpp"

class KruskElem
{
public:
    int from, to, distance; // The edge being stored
    KruskElem()
    {
        from = -1;
        to = -1;
        distance = -1;
    }
    KruskElem(int f, int t, int d)
    {
        from = f;
        to = t;
        distance = d;
    }
};
void Kruskel(Graph *G)
{ // Kruskal’s MST algorithm
    ParPtrTree A(G->n());
    KruskElem E[G->e()];
    int i;
    int edgecnt = 0;
    // Equivalence class array
    // Array of edges for min-heap
    for (i = 0; i < G->n(); i++) // Put the edges on the array
        for (int w = G->first(i); w < G->n(); w = G->next(i, w))
        {
            E[edgecnt].distance = G->weight(i, w);
            E[edgecnt].from = i;
            E[edgecnt++].to = w;
        }
    // Heapify the edges
    heap<KruskElem, Comp> H(E, edgecnt, edgecnt);
    int numMST = G->n();
    // Initially n equiv classes
    for (i = 0; numMST > 1; i++)
    { // Combine equiv classes
        KruskElem temp;
        temp = H.removefirst(); // Get next cheapest edge
        int v = temp.from;
        int u = temp.to;
        if (A.differ(v, u))
        { // If in different equiv classes
            A.UNION(v, u);
            // Combine equiv classes
            AddEdgetoMST(temp.from, temp.to); // Add edge to MST
            numMST--;
            // One less MST
        }
    }
}