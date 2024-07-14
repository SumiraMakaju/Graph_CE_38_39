#include <iostream>
#include <vector>
#include "graph.h"

using namespace std;

int main() {
    int n;
    cout << "Enter the number of vertices in the graph: ";
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(n, 0));
    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> arr[i][j];
        }
    }

    Graph g(arr);

    cout << "Graph adjacency matrix:\n";
    g.printGraph();

    cout << "Number of edges: " << g.numEdges() << endl;
    cout << "In-degree of vertex 3: " << g.indegree(2) << endl;
    cout << "Out-degree of vertex 2: " << g.outdegree(1) << endl;
    cout << "Degree of vertex 3: " << g.degree(2) << endl;

    vector<int> neighbours = g.neighbours(2);
    cout << "Neighbours of vertex 3: ";
    for (int v : neighbours) {
        cout << v << " ";
    }
    cout << endl;

    cout << "Are vertex 2 and vertex 3 neighbours? " << (g.areNeighbours(1, 2) ? "Yes" : "No") << endl;

    // Additional functionalities
    cout << "Is the graph empty? " << (g.isEmpty() ? "Yes" : "No") << endl;
    cout << "Is the graph directed? " << (g.isDirected() ? "Yes" : "No") << endl;

    cout << "Adding a vertex...\n";
    g.addVertex();
    g.printGraph();

    cout << "Adding an edge between vertex 1 and vertex 2...\n";
    g.addEdge(0, 1);
    g.printGraph();

    cout << "Removing the edge between vertex 1 and vertex 2...\n";
    g.removeEdge(0, 1);
    g.printGraph();

    cout << "Number of vertices: " << g.getNumVertices() << endl;

    cout << "Removing vertex 2...\n";
    g.removeVertex(1);
    g.printGraph();

    return 0;
}
