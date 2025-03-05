
#include "graph.hpp"
#include <iostream>
#include <cassert>
#include <complex>
// #include <vector>

using namespace std;

// Implementation for the adjacency matrix representation
class Graphm : public Graph
{
private:
    int numVertex, numEdge; // Store number of vertices, edges
    int *mark;

    complex<double> **matrix;       // Pointer to adjacency matrix
    complex<double> **admit_matrix; // Pointer to admittance matrix

public:
    Graphm(int numVert)
    {
        Init(numVert);
    }
    ~Graphm()
    {
        // Pointer to mark array
        // Constructor
        // Destructor
        delete[] mark; // Return dynamically allocated memory

        for (int i = 0; i < numVertex; i++)
            delete[] matrix[i];
        delete[] matrix;

        for (int i = 0; i < numVertex; i++)
            delete[] admit_matrix[i];
        delete[] admit_matrix;
    }
    void Init(int n)    // Initialize the graph
    {
        int i;
        numVertex = n;
        numEdge = 0;
        mark = new int[n];
        // Initialize mark array
        for (i = 0; i < numVertex; i++)
            mark[i] = 0;                       // UNVISITED = 0
        
        matrix = (complex<double> **)new complex<double> *[numVertex]; // Make matrix
        for (i = 0; i < numVertex; i++)
            matrix[i] = new complex<double>[numVertex];
        for (i = 0; i < numVertex; i++) // Initialize to 0 weights
            for (int j = 0; j < numVertex; j++)
                matrix[i][j] = 0;                                           // !!!
        
        admit_matrix = (complex<double> **)new complex<double> *[numVertex]; // Make matrix
        for (i = 0; i < numVertex; i++)
            admit_matrix[i] = new complex<double>[numVertex];
        for (i = 0; i < numVertex; i++) // Initialize to 0
            for (int j = 0; j < numVertex; j++)
                admit_matrix[i][j] = {0, 0};
    }
    int n() { return numVertex; } // Number of vertices
    int e() { return numEdge; }   // Number of edges
    // Return first neighbor of "v"
    int first(int v)
    {
        for (int i = 0; i < numVertex; i++)
            if (matrix[v][i] != complex<double> {0,0}) // ?????
                return i;
        return numVertex;
        // Return n if none
    }
    // Return v’s next neighbor after w
    int next(int v, int w)
    {
        for (int i = w + 1; i < numVertex; i++)
            if (matrix[v][i] != complex<double> {0,0}) // ?????
                return i;
        return numVertex;
        // Return n if none
    }
    // Set edge (v1, v2) to "wt"
    void setEdge(int v1, int v2, complex<double> wt)
    {
        // Assert(wt>0, "Illegal weight value");            // use cassert
        // assert(real(wt) > 0 && "Illegal weight value");     // real part need to be positive
        if (matrix[v1][v2] == complex<double> {0,0})        // ???
            numEdge++;
        matrix[v1][v2] = wt;
    }
    void delEdge(int v1, int v2)
    { // Delete edge (v1, v2)
        if (matrix[v1][v2] != complex<double> {0,0})
            numEdge--;
        matrix[v1][v2] = complex<double> {0,0};
    }
    bool isEdge(int i, int j) // Is (i, j) an edge?
    {
        return matrix[i][j] != complex<double> {0,0};
    }
    complex<double> weight(int v1, int v2) { return matrix[v1][v2]; }   // changed type in ADT
    int getMark(int v) { return mark[v]; }
    void setMark(int v, int val) { mark[v] = val; }

    complex<double> **adjMatrix() { return matrix; }

    complex<double> **admitMatrix()
    {
        for (int i = 0; i < numVertex; i++)
        {
            complex<double> sum = 0; //  diagonal term
            for (int j = 0; j < numVertex; j++)
            {
                sum += matrix[i][j];
            }
            admit_matrix[i][i] = sum;
            for (int j = 0; j < numVertex; j++) // off-diagonal term
            {
                if (i != j)
                {
                    admit_matrix[i][j] = -matrix[i][j];
                }
            }
        }
        return admit_matrix;
    }

    void printMatrix(complex<double> **matrix) {
        for (int i = 0; i < numVertex; i++) {
            for (int j = 0; j < numVertex; j++) {
                cout << matrix[i][j] << "\t";
            }
            cout << endl; 
        }    
    }
    
};