 #include "graph.h"
#include <iostream>
#include <vector>

Graph::Graph(const std::vector<std::vector<int>>& adjacentmatrix) : adjacentmatrix(adjacentmatrix), numvertices(adjacentmatrix.size()) {}

Graph::Graph(int numvertices) : numvertices(numvertices), adjacentmatrix(numvertices, std::vector<int>(numvertices, 0)) {}

void Graph::printGraph() const {
    for (int i = 0; i < numvertices; ++i) {
        for (int j = 0; j < numvertices; ++j) {
            std::cout << adjacentmatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int Graph::numEdges() const {
    int count = 0;
    for (int i = 0; i < numvertices; ++i) {
        for (int j = 0; j < numvertices; ++j) {
            if (adjacentmatrix[i][j] == 1) {
                ++count;
            }
        }
    }
    return count;
}

int Graph::indegree(int vertex) const {
    int count = 0;
    for (int i = 0; i < numvertices; ++i) {
        if (adjacentmatrix[i][vertex] != 0) {
            ++count;
        }
    }
    return count;
}

int Graph::outdegree(int vertex) const {
    int count = 0;
    for (int i = 0; i < numvertices; ++i) {
        if (adjacentmatrix[vertex][i] != 0) {
            ++count;
        }
    }
    return count;
}

int Graph::degree(int vertex) const {
    return outdegree(vertex) + indegree(vertex);
}

std::vector<int> Graph::neighbours(int vertex) const {
    std::vector<int> neighbors;
    for (int i = 0; i < numvertices; ++i) {
        if (adjacentmatrix[vertex][i] != 0) {
            neighbors.push_back(i);
        }
    }
    return neighbors;
}

bool Graph::areNeighbours(int vertex1, int vertex2) const {
    return adjacentmatrix[vertex1][vertex2] != 0;
}
