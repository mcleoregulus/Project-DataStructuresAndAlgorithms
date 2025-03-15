#ifndef GRAPHL_HPP
#define GRAPHL_HPP

#include "graph.hpp"
#include "edge.hpp"
#include "LList.hpp"

class Graphl : public Graph
{
private:
    // List<Edge> **vertex;
    LList<LList<Edge> *> *vertex; // 邻接表使用二重单链表，构建动态图
    int numVertex, numEdge;
    // int *mark;
    LList<int> *mark; // 动态mark数组也需单链表

public:
    Graphl() { Init(); }
    Graphl(int numVert) { Init(numVert); }
    ~Graphl()
    {
        // Number of vertices, edges
        // Pointer to mark array
        // Destructor
        // delete[] mark; // Return dynamically allocated memory
        // for (int i = 0; i < numVertex; i++)
        //     delete[] vertex[i];
        // delete[] vertex;
        mark->clear();
        delete mark;
        vertex->moveToStart();
        while (vertex->currPos() < vertex->length())
        {
            vertex->getValue()->clear();
            delete vertex->getValue();
            vertex->next();
        }
        vertex->clear();
        delete vertex;
    }
    void Init()
    {
        numVertex = 0;
        numEdge = 0;
        mark = new LList<int>();
        vertex = new LList<LList<Edge> *>();
    }
    void Init(int n)
    {
        numVertex = n;
        numEdge = 0;
        mark = new LList<int>(); // Initialize mark array
        for (int i = 0; i < numVertex; i++)
            mark->append(UNVISITED);
        // Create and initialize adjacency lists
        // vertex = (List<Edge> **)new List<Edge> *[numVertex];
        // for (i = 0; i < numVertex; i++)
        //     vertex[i] = new LList<Edge>();
        vertex = new LList<LList<Edge> *>();
        for (int i = 0; i < numVertex; i++)
            vertex->append(new LList<Edge>());
    }
    int n() { return numVertex; } // Number of vertices
    int e() { return numEdge; }   // Number of edges
    int first(int v)
    { // Return first neighbor of "v"
        vertex->moveToPos(v);
        LList<Edge> *currVert = vertex->getValue();
        if (currVert->length() == 0)
            return numVertex;
        // No neighbor
        currVert->moveToStart();
        Edge it = currVert->getValue();
        return it.vertex();
    }
    // Get v’s next neighbor after w
    int next(int v, int w)
    {
        vertex->moveToPos(v);
        LList<Edge> *currVert = vertex->getValue();
        Edge it;
        if (isEdge(v, w))
        {
            if ((currVert->currPos() + 1) < currVert->length())
            {
                currVert->next();
                it = currVert->getValue();
                return it.vertex();
            }
        }
        return n(); // No neighbor
    }
    // Set edge (i, j) to "weight"
    void setEdge(int i, int j, Complex weight)
    {
        // Assert(weight>0, "May not set weight to 0");                     //assert
        vertex->moveToPos(i);
        LList<Edge> *currVert = vertex->getValue();
        Edge currEdge(j, weight);
        if (isEdge(i, j))
        { // Edge already exists in graph
            currVert->remove();
            currVert->insert(currEdge);
        }
        else
        { // Keep neighbors sorted by vertex index
            numEdge++;
            for (currVert->moveToStart();
                 currVert->currPos() < currVert->length();
                 currVert->next())
            {
                Edge temp = currVert->getValue();
                if (temp.vertex() > j)
                    break;
            }
            currVert->insert(currEdge);
        }
    }
    void delEdge(int i, int j)
    { // Delete edge (i, j)
        vertex->moveToPos(i);
        LList<Edge> *currVert = vertex->getValue();
        if (isEdge(i, j))
        {
            currVert->remove();
            numEdge--;
        }
    }
    bool isEdge(int i, int j)
    { // Is (i,j) an edge?
        vertex->moveToPos(i);
        LList<Edge> *currVert = vertex->getValue();
        Edge it;
        for (currVert->moveToStart();
             currVert->currPos() < currVert->length();
             currVert->next())
        {
            // Check whole list
            Edge temp = currVert->getValue();
            if (temp.vertex() == j)
                return true;
        }
        return false;
    }
    Complex weight(int i, int j)
    { // Return weight of (i, j)
        vertex->moveToPos(i);
        LList<Edge> *currVert = vertex->getValue();
        Edge curr;
        if (isEdge(i, j))
        {
            curr = currVert->getValue();
            return curr.weight();
        }
        else
            return 0;
    }
    // int getMark(int v) { return mark[v]; }
    // void setMark(int v, int val) { mark[v] = val; }
    int getMark(int v)
    {
        mark->moveToPos(v);
        // mark->print();
        return mark->getValue();
    }
    void setMark(int v, int val)
    {
        mark->moveToPos(v);
        mark->remove();
        mark->insert(val);
    }

    const LList<LList<Edge> *> *getAdjList() const { return vertex; }

    void addVertex(int v = 1)
    {
        for (int i = 0; i < v; ++i)
        {
            vertex->append(new LList<Edge>());
            mark->append(UNVISITED);
            numVertex++;
        }
    }

    void delVertex(int v = -1)
    {
        v = v == -1 ? numVertex - 1 : v;
        if (v < 0 || v >= numVertex)
        {
            cout << "Error: delVertex(v) Vertex not found! \n";
            return;
        }

        // 删除与该顶点相关的所有边
        // 遍历所有顶点，删除它们与v相连的边
        for (int i = 0; i < numVertex; i++)
        {
            if (i == v)
            {
                continue;
            }
            vertex->moveToPos(i);
            LList<Edge> *currVert = vertex->getValue();
            // Edge it;
            for (currVert->moveToStart(); currVert->currPos() < currVert->length(); currVert->next())
            {
                Edge temp = currVert->getValue();
                if (temp.vertex() == v)
                {
                    // 找到与v相连的边，删除
                    currVert->remove();
                    numEdge--;
                    break;
                }
            }
        }

        // 删除该顶点的邻接表
        vertex->moveToPos(v);
        numEdge -= vertex->getValue()->length();
        delete vertex->getValue();
        vertex->remove();

        // 删除该顶点的mark标记
        mark->moveToPos(v);
        mark->remove();

        // 调整顶点索引
        // 如果删除的不是最后一个顶点，需要调整后续顶点的索引
        // if (v != numVertex - 1)
        // {
        //     // 遍历所有顶点的邻接表，调整顶点索引
        //     for (int i = 0; i < numVertex - 1; i++)
        //     {
        //         vertex->moveToPos(i);
        //         LList<Edge> *currVert = vertex->getValue();
        //         Edge it;
        //         for (currVert->moveToStart(); currVert->currPos() < currVert->length(); currVert->next())
        //         {
        //             Edge temp = currVert->getValue();
        //             if (temp.vertex() > v)
        //             {
        //                 // 如果顶点索引大于v，减1
        //                 temp.setVertex(temp.vertex() - 1);
        //                 currVert->remove();
        //                 currVert->insert(temp);
        //             }
        //         }
        //     }
        // }

        numVertex--;
    }

    void printAdjList()
    {
        LList<LList<Edge> *> *const &adjList = vertex;
        for (int i = 0; i < numVertex; i++)
        {
            adjList->moveToPos(i);
            LList<Edge> *currVertEdges = adjList->getValue();
            cout << "Vertex " << i << " -> ";
            currVertEdges->moveToStart();
            while (currVertEdges->currPos() < currVertEdges->length())
            {
                Edge e = currVertEdges->getValue();
                cout << "(" << e.vertex() << ", " << e.weight() << ") ";
                currVertEdges->next();
            }
            cout << endl;
        }
    }

    void printMark()
    {
        cout << "Mark: ";
        LList<int> *const &markList = mark;
        markList->moveToStart();
        while (markList->currPos() < markList->length()) {
            cout << markList->getValue() << " ";
            markList->next();
        }
        cout << endl;
    }
};

#endif // GRAPHL_HPP