
// 这些实现的用户必须添加相应功能，例如从文件中读取图描述。可以使用ADT提供的setEdge函数逐步构建图。
// 定义一个复数带权图

// Graph abstract class. This ADT assumes that the number
// of vertices is fixed when the graph is created.

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <complex>
using namespace std;
typedef complex<double> Complex;
const int VISITED = 1;
const int UNVISITED = 0;

class Graph
{
private:
    void operator=(const Graph &) {}
    Graph(const Graph &) {}
    // Protect assignment
    // Protect copy constructor
public:
    Graph() {}
    // Default constructor
    virtual ~Graph() {} // Base destructor
    // Initialize a graph of n vertices
    virtual void Init(int n) = 0;
    // Return: the number of vertices and edges
    virtual int n() = 0;
    virtual int e() = 0;
    // Return v’s first neighbor
    virtual int first(int v) = 0;
    // Return v’s next neighbor
    virtual int next(int v, int w) = 0;
    // Set the weight for an edge
    // i, j: The vertices
    // wgt: Edge weight
    virtual void setEdge(int v1, int v2, Complex wght) = 0;
    // Delete an edge
    // i, j: The vertices
    virtual void delEdge(int v1, int v2) = 0;
    // Determine if an edge is in the graph
    // i, j: The vertices
    // Return: true if edge i,j has non-zero weight
    virtual bool isEdge(int i, int j) = 0;
    // Return an edge’s weight
    // i, j: The vertices
    // Return: The weight of edge i,j, or zero
    virtual Complex weight(int v1, int v2) = 0; // changed type
    // Get and Set the mark value for a vertex
    // v: The vertex
    // val: The value to set
    virtual int getMark(int v) = 0;
    virtual void setMark(int v, int val) = 0;
};

// VISITED = 1, UNVISITED = 0

#endif // GRAPH_HPP