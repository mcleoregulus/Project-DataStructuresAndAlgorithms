
// #include "graph.hpp"

// class DijkElem
// {
// public:
//     int vertex, distance;
//     DijkElem()
//     {
//         vertex = -1;
//         distance = -1;
//     }
//     DijkElem(int v, int d)
//     {
//         vertex = v;
//         distance = d;
//     }
// };

// // Dijkstra’s shortest paths algorithm with priority queue（优先队列/最小堆）  //稀疏图
// void Dijkstra(Graph *G, int *D, int s)
// {
//     int i, v, w;
//     DijkElem temp;
//     DijkElem E[G->e()];
//     // v is current vertex
//     // Heap array with lots of space
//     temp.distance = 0;
//     temp.vertex = s;
//     E[0] = temp;
//     // Initialize heap array
//     heap<DijkElem, DDComp> H(E, 1, G->e()); // Create heap          00000
//     for (i = 0; i < G->n(); i++)
//     {
//         // Now, get distances
//         do
//         {
//             if (H.size() == 0)
//                 return; // Nothing to remove
//             temp = H.removefirst();
//             v = temp.vertex;
//         } while (G->getMark(v) == VISITED);
//         G->setMark(v, VISITED);
//         if (D[v] == INFINITY)
//             return;
//         // Unreachable vertices
//         for (w = G->first(v); w < G->n(); w = G->next(v, w))
//             if (D[w] > (D[v] + G->weight(v, w)))
//             { // Update D
//                 D[w] = D[v] + G->weight(v, w);
//                 temp.distance = D[w];
//                 temp.vertex = w;
//                 H.insert(temp); // Insert new distance in heap
//             }
//     }
// }