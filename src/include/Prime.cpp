
// #include "graph.hpp"
// #include "heap.hpp"
// #include <complex>
// #include <vector>

// // Prim’s MST algorithm: priority queue version
// void Prim(Graph *G, int *D, int s)
// {
//     int i, v, w;
//     int V[G->n()];
//     DijkElem temp;
//     DijkElem E[G->e()];
//     // "v" is current vertex
//     // V[I] stores I’s closest neighbor
//     // Heap array with lots of space
//     temp.distance = 0;
//     temp.vertex = s;
//     E[0] = temp;
//     // Initialize heap array
//     heap<DijkElem, DDComp> H(E, 1, G->e()); // Create heap
//     for (i = 0; i < G->n(); i++)
//     {
//         // Now build MST
//         do
//         {
//             if (H.size() == 0)
//                 return; // Nothing to remove
//             temp = H.removefirst();
//             v = temp.vertex;
//         } while (G->getMark(v) == 1); // VISITED
//         G->setMark(v, 1); // VISITED
//         if (v != s)
//             AddEdgetoMST(V[v], v); // Add edge to MST
//         if (D[v] == INFINITY)
//             return;
//         // Ureachable vertex
//         for (w = G->first(v); w < G->n(); w = G->next(v, w))
//             if (D[w] > abs(G->weight(v, w)))
//             {
//                 // Update D
//                 D[w] = abs(G->weight(v, w));
//                 V[w] = v;
//                 // Update who it came from
//                 temp.distance = D[w];
//                 temp.vertex = w;
//                 H.insert(temp); // Insert new distance in heap
//             }
//     }
// }

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

// // void Prim(Graph *G, int *D, int s)
// // { // Prim’s MST algorithm
// //     int V[G->n()];
// //     int i, w;
// //     for (i = 0; i < G->n(); i++)
// //     {
// //         int v = minVertex(G, D);
// //         G->setMark(v, 1); // VISITED
// //         if (v != s)
// //             AddEdgetoMST(V[v], v);
// //         if (D[v] == INFINITY)
// //             return;
// //         // Store closest vertex
// //         // Process the vertices
// //         // Add edge to MST
// //         // Unreachable vertices
// //         for (w = G->first(v); w < G->n(); w = G->next(v, w))
// //             if (D[w] > G->weight(v, w))
// //             {
// //                 D[w] = G->weight(v, w);
// //                 // Update distance
// //                 V[w] = v;
// //             }
// //     }
// // }