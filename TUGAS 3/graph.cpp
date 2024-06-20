#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Graph {
    int V;    
    vector<list<int>> adj; 

public:
    Graph(int V);

    void addEdge(int v, int w);

    void printGraph() const;
};

Graph::Graph(int V) : V(V), adj(V) {}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w); 
    adj[w].push_back(v); 
}

void Graph::printGraph() const {
    for (int v = 0; v < V; ++v) {
        cout << "Simpul " << v << ": ";
        for (auto x : adj[v])
            cout << x << " ";
        cout << endl;
    }
}

int main() {
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.printGraph();

    return 0;
}
