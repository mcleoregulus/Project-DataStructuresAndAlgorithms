
#include "graph.hpp"
#include <iostream>
#include <cassert>
#include <complex>
#include <vector>

using namespace std;

// Implementation for the adjacency matrix representation
class Graphm : public Graph
{
private:
    int numVertex, numEdge; // Store number of vertices, edges
    vector<int> mark;       // Use vector for mark array

    vector<vector<complex<double>>> matrix;       // Use vector of vectors for adjacency matrix
    vector<vector<complex<double>>> admit_matrix; // Use vector of vectors for admittance matrix

public:
    Graphm(int numVert)
    {
        Init(numVert);
    }
    ~Graphm()
    {
        // Destructor
        // No need to manually delete memory for vectors
    }
    void Init(int n) // Initialize the graph
    {
        int i;
        numVertex = n;
        numEdge = 0;
        mark.resize(n, 0); // Initialize mark array with 0 (UNVISITED)

        // Initialize adjacency matrix
        matrix.resize(numVertex, vector<complex<double>>(numVertex, complex<double>(0, 0)));

        // Initialize admittance matrix
        admit_matrix.resize(numVertex, vector<complex<double>>(numVertex, complex<double>(0, 0)));
    }
    int n() { return numVertex; } // Number of vertices
    int e() { return numEdge; }   // Number of edges
    // Return first neighbor of "v"
    int first(int v)
    {
        for (int i = 0; i < numVertex; i++)
            if (matrix[v][i] != complex<double>(0, 0))
                return i;
        return numVertex;
        // Return n if none
    }
    // Return v’s next neighbor after w
    int next(int v, int w)
    {
        for (int i = w + 1; i < numVertex; i++)
            if (matrix[v][i] != complex<double>(0, 0))
                return i;
        return numVertex;
        // Return n if none
    }
    // Set edge (v1, v2) to "wt"
    void setEdge(int v1, int v2, complex<double> wt)
    {
        // Assert(wt>0, "Illegal weight value");               // use cassert
        // assert(real(wt) > 0 && "Illegal weight value");     // real part need to be positive
        if (matrix[v1][v2] == complex<double>(0, 0)) // ???
            numEdge++;
        matrix[v1][v2] = wt;
    }
    void delEdge(int v1, int v2)
    { // Delete edge (v1, v2)
        if (matrix[v1][v2] != complex<double>(0, 0))
            numEdge--;
        matrix[v1][v2] = complex<double>(0, 0);
    }
    bool isEdge(int i, int j) // Is (i, j) an edge?
    {
        return matrix[i][j] != complex<double>(0, 0);
    }
    complex<double> weight(int v1, int v2) { return matrix[v1][v2]; } // changed type in ADT
    int getMark(int v) { return mark[v]; }
    void setMark(int v, int val) { mark[v] = val; }

    vector<vector<complex<double>>> adjMatrix() { return matrix; }

    vector<vector<complex<double>>> admitMatrix()
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

    void printMatrix(vector<vector<complex<double>>> matrix)
    {
        for (int i = 0; i < numVertex; i++)
        {
            for (int j = 0; j < numVertex; j++)
            {
                cout << matrix[i][j] << "\t";
            }
            cout << endl;
        }
    }
};