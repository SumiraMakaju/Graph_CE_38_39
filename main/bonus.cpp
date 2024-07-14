#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include "graph.h"
int main() {
    Graph graph;
    graph.generateRandomGraph(5, 10);

    std::cout << "Number of vertices: " << graph.getNumVertices() << std::endl;
    std::cout << "Number of edges: " << graph.numEdges() << std::endl;

    for (int i = 0; i < 5; ++i) {
        std::cout << "Neighbours of vertex " << i << ": ";
        for (int v : graph.neighbours(i)) {
            std::cout << v << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}