
#include "graph.hpp"

// Edge class for Adjacency List graph representation
class Edge
{
    int vert;
    Complex wt;

public:
    Edge()
    {
        vert = -1;
        wt = Complex(0,0); // -1
    }
    Edge(int v, Complex w)
    {
        vert = v;
        wt = w;
    }
    int vertex() const { return vert; } // const
    Complex weight() const { return wt; }
};