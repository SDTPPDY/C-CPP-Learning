#include <iostream>
using namespace std;

#define inf -1

// 图的邻接表表示
class Graph {
  private:
    struct EdgeNode {
        int vertex;
        int weight;
        EdgeNode* next;
    };

    struct VertexNode {
        int vertex;
        EdgeNode* head;
    };

    int vertices;
    VertexNode* nodes;

  public:
    Graph(int vertices) {
        this->vertices = vertices;
        this->nodes = new VertexNode[vertices];

        for (int i = 0; i < vertices; i++) {
            nodes[i].vertex = i;
            nodes[i].head = nullptr;
        }
    }
    ~Graph() {
        for (int i = 0; i < vertices; i++) {
            EdgeNode* curr = nodes[i].head;
            while (curr) {
                EdgeNode* temp = curr;
                curr = curr->next;
                delete temp;
            }
        }

        delete[] nodes;
    }
    void AddEdge(int u, int v, int w) {
        EdgeNode* new_node = new EdgeNode;
        new_node->vertex = v;
        new_node->weight = w;
        new_node->next = nodes[u].head;
        nodes[u].head = new_node;
    }
    void PrintGraph() {
        for (int i = 0; i < vertices; ++i) {
            EdgeNode* curr = nodes[i].head;
            cout << "Vertex " << i << ": ";
            while (curr) {
                cout << curr->vertex << "(" << curr->weight << ")";
                curr = curr->next;
            }
            cout << endl;
        }
    }
};

// 图的邻接矩阵表示
class graph {
  private:
    int vertices;
    int** edges;

  public:
    graph(int vertices) {
        this->vertices = vertices;
        edges = new int*[vertices];
        for (int i = 0; i < vertices; i++) {
            edges[i] = new int[vertices];
            for (int j = 0; j < vertices; j++) {
                edges[i][j] = inf;
            }
        }
    }
    ~graph() {
        for (int i = 0; i < vertices; i++) {
            delete[] edges[i];
        }
        delete[] edges;
    }
    void addEdge(int u, int v, int w) {
        edges[u][v] = w;
    }
    void printGraph() {
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                cout << edges[i][j] << ' ';
            }
            cout << endl;
        }
    }
};

int main() {
    int vertices = 5;
    graph gph(vertices);

    gph.addEdge(0, 1, 1);
    gph.addEdge(0, 2, 3);
    gph.addEdge(2, 3, 7);
    gph.addEdge(3, 4, 9);
    gph.addEdge(4, 0, 4);
    gph.addEdge(4, 2, 5);

    gph.printGraph();

    cout << "----------" << endl;

    Graph grph(5);
    grph.AddEdge(0, 1, 4);
    grph.AddEdge(0, 2, 2);
    grph.AddEdge(1, 2, 3);
    grph.AddEdge(2, 3, 4);
    grph.AddEdge(3, 4, 2);

    grph.PrintGraph();
}