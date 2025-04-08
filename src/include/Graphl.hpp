#ifndef GRAPHL_HPP
#define GRAPHL_HPP

#include "graph.hpp"
#include "edge.hpp"
#include "LList.hpp"

class Graphl : public Graph
{
private:
    // List<Edge> **vertex;
    LList<LList<Edge> *> *vertex; // 邻接表使用二重指针单链表，构建动态图
    int numVertex, numEdge;
    // int *mark;
    LList<int> *mark; // 动态mark数组也需单链表

public:
    Graphl(int numVert = 0) { Init(numVert); }
    ~Graphl()
    {
        // Number of vertices, edges
        // Pointer to mark array
        // Destructor
        // delete[] mark; // Return dynamically allocated memory
        // for (int i = 0; i < numVertex; i++)
        //     delete[] vertex[i];
        // delete[] vertex;

        // mark->clear();
        delete mark;
        vertex->moveToStart();
        while (vertex->currPos() < vertex->length())
        {
            // vertex->getValue()->clear();
            delete vertex->getValue();
            vertex->next();
        }
        // vertex->clear();
        delete vertex;
    }
    void Init(int n = 0)
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
        LList<Edge> *const &currVert = vertex->getValue();
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
        LList<Edge> *const &currVert = vertex->getValue();
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
        if (i == j) {
            cerr << "Error: Invalid Input! setEdge: " << i << " to " << j << endl;
            return;
        }
        if (real(weight) <= 0) {
            cerr << "Error: May not set resistance to negative! setEdge: " << i << " to " << j << endl;
            return;
        }

        while (numVertex < i + 1 || numVertex < j + 1) // 自动增加顶点
        {
            addVertex();
        }
        vertex->moveToPos(i);
        LList<Edge> *const &currVert = vertex->getValue();
        Edge currEdge(j, weight);
        if (isEdge(i, j))
        { // Edge already exists in graph
            currVert->remove();
            currVert->insert(currEdge);
        }
        else
        { // Keep neighbors sorted by vertex index
            numEdge++;
            for (currVert->moveToStart(); currVert->currPos() < currVert->length(); currVert->next())
            {
                Edge temp = currVert->getValue();
                if (temp.vertex() > j)
                    break;
            }
            currVert->insert(currEdge);
        }
    }
    void delEdge(int i, int j) // Delete edge (i, j)
    {
        if (i >= numVertex || j >= numVertex || i < 0 || j < 0 || i == j) {
            cerr << "Error: Invalid Input: Out of Index! delEdge: " << i << " to " << j << endl;
            return;
        }
        vertex->moveToPos(i);
        LList<Edge> *const &currVert = vertex->getValue();
        if (isEdge(i, j))
        {
            currVert->remove();
            numEdge--;
        }
    }
    bool isEdge(int i, int j) // Is (i,j) an edge?
    {
        if (i >= numVertex || j >= numVertex || i < 0 || j < 0 || i == j) {
            cerr << "Error: Invalid Input: Out of Index! isEdge: " << i << " to " << j << endl;
            return false;
        }
        vertex->moveToPos(i);
        LList<Edge> *const &currVert = vertex->getValue();
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
        if (i >= numVertex || j >= numVertex || i < 0 || j < 0 || i == j) {
            cerr << "Error: Invalid Input: Out of Index! getWeight: " << i << " to " << j << endl;
            return 0;
        }
        vertex->moveToPos(i);
        LList<Edge> *const &currVert = vertex->getValue();
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
        if (v >= numVertex || v < 0) {
            cerr << "Error: Invalid Input: Out of Index! getMark: " << v << endl;
            return UNVISITED;
        }
        mark->moveToPos(v);
        // mark->print();
        return mark->getValue();
    }
    void setMark(int v, int val)
    {
        if (v >= numVertex || v < 0) {
            cerr << "Error: Invalid Input: Out of Index! setMark: " << v << endl;
            return;
        }
        mark->moveToPos(v);
        mark->remove();
        mark->insert(val);
    }

    LList<LList<Edge> *> *getAdjList() const { return vertex; }

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
            cerr << "Error: delVertex(v) Vertex not found! \n";
            return;
        }

        // 删除与该顶点相关的所有边: 1.遍历所有顶点，删除它们与v相连的边
        LList<LList<Edge> *> *const &adjList = getAdjList();
        for (adjList->moveToStart(); adjList->currPos() < adjList->length(); adjList->next())
        {
            if (adjList->currPos() == v)
            {
                continue;
            }

            LList<Edge> *const &currVert = adjList->getValue();
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

        // 2. 删除该顶点的邻接表
        vertex->moveToPos(v);
        numEdge -= vertex->getValue()->length();
        delete vertex->getValue();
        vertex->remove();

        // 3. 删除该顶点的mark标记
        mark->moveToPos(v);
        mark->remove();

        // 4. 调整顶点索引: 如果删除的不是最后一个顶点，需要调整后续顶点的索引
        if (v != numVertex - 1)
        {
            // 遍历所有顶点的邻接表，调整顶点索引
            for (vertex->moveToStart(); vertex->currPos() < vertex->length(); vertex->next())
            {
                LList<Edge> *const &currVert = adjList->getValue();
                for (currVert->moveToStart(); currVert->currPos() < currVert->length(); currVert->next())
                {
                    Edge temp = currVert->getValue();
                    if (temp.vertex() > v)
                    {
                        // 如果顶点索引大于v，减1
                        currVert->remove();
                        currVert->insert(Edge(temp.vertex() - 1, temp.weight()));
                    }
                }
            }
        }

        numVertex--;
    }

    void printAdjList()
    {
        LList<LList<Edge> *> *const &adjList = vertex;

        for (adjList->moveToStart(); adjList->currPos() < adjList->length(); adjList->next())
        {
            LList<Edge> *const &currVert = adjList->getValue();
            cout << "Vertex " << adjList->currPos() << " -> ";
            for (currVert->moveToStart(); currVert->currPos() < currVert->length(); currVert->next())
            {
                Edge e = currVert->getValue();
                cout << "(" << e.vertex() << ", " << e.weight() << ") ";
            }
            cout << endl;
        }
    }

    void printMark()
    {
        cout << "Mark: ";
        LList<int> *const &markList = mark;
        markList->moveToStart();
        while (markList->currPos() < markList->length())
        {
            cout << markList->getValue() << " ";
            markList->next();
        }
        cout << endl;
    }

    Complex **getAdmitMatrix()
    {
        // 获取邻接表
        LList<LList<Edge> *> *const &adjList = getAdjList();

        // 初始化导纳矩阵
        Complex **admit_matrix = new Complex *[numVertex];
        for (int i = 0; i < numVertex; i++)
        {
            admit_matrix[i] = new Complex[numVertex];
            for (int j = 0; j < numVertex; j++)
            {
                admit_matrix[i][j] = Complex(0, 0); // 初始化为0
            }
        }

        // 遍历每个顶点
        for (int i = 0; i < numVertex; i++)
        {
            Complex sum = Complex(0, 0); // 对角线元素的和

            // 获取当前顶点的邻接边
            adjList->moveToPos(i);
            LList<Edge> *const &currEdges = adjList->getValue();

            // 遍历邻接边
            currEdges->moveToStart();
            while (currEdges->currPos() < currEdges->length())
            {
                Edge e = currEdges->getValue();
                int j = e.vertex();          // 相连的顶点
                Complex weight = e.weight(); // 边的权重

                // 非对角线元素：负导纳
                admit_matrix[i][j] = Complex(-1, 0) / weight;

                // 累加对角线元素
                sum += Complex(1, 0) / weight;

                currEdges->next();
            }

            // 对角线元素：总导纳
            admit_matrix[i][i] = sum;
        }
        return admit_matrix;
    }

    void printAdmitMatrix()
    {
        Complex **admit_matrix = getAdmitMatrix();
        for (int i = 0; i < numVertex; ++i)
        {
            for (int j = 0; j < numVertex; ++j)
            {
                cout << admit_matrix[i][j] << "\t";
            }
            cout << endl;
        }
    }

    void setBranch(int node1, int node2, Complex impedance)
    {
        setEdge(node1 - 1, node2 - 1, impedance);
        setEdge(node2 - 1, node1 - 1, impedance);
    }

    // 邻接表转邻接矩阵
    Complex **getAdjMatrix()
    {

        Complex **matrix = new Complex *[numVertex];
        for (int i = 0; i < numVertex; i++)
        {
            matrix[i] = new Complex[numVertex];
            for (int j = 0; j < numVertex; j++)
            {
                matrix[i][j] = Complex(0, 0);
            }
        }

        LList<LList<Edge> *> *const &adjList = getAdjList();
        adjList->moveToStart();
        while (adjList->currPos() < adjList->length())
        {

            LList<Edge> *const &currEdges = adjList->getValue();
            currEdges->moveToStart();
            while (currEdges->currPos() < currEdges->length())
            {
                matrix[adjList->currPos()][currEdges->getValue().vertex()] = currEdges->getValue().weight();
                currEdges->next();
            }
            adjList->next();
        }
        return matrix;
    }
};

#endif // GRAPHL_HPP