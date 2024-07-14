#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include "graph.h"

Graph::Graph() : numVertices(0), numEdge(0), numInDegree(0), numOutDegree(0), vertexDegree(0) {}

bool Graph::isEmpty() {
    return numVertices == 0;
}

bool Graph::isDirected() {
    if(numVertices == 0)
        std::cout << "Vertex Does Not Exist!";
    else
        return true;
}

void Graph::addVertex(int vertex) {
    std::cout << "Adding vertex: " << vertex << std::endl;

    if (std::find(vertices.begin(), vertices.end(), vertex) != vertices.end()) {
        std::cerr << "Vertex already exists!" << std::endl;
        return;
    }

    vertices.push_back(vertex);
    numVertices++;

    std::cout << "Resizing adjMatrix to: " << numVertices << std::endl;
    adjMatrix.resize(numVertices);

    for (int i = 0; i < numVertices; ++i) {
        adjMatrix[i].resize(numVertices);
    }

    for (int i = 0; i < numVertices; ++i) {
        adjMatrix[i][numVertices - 1] = 0;
        adjMatrix[numVertices - 1][i] = 0;
    }
}

void Graph::addEdge(int vertex1, int vertex2) {
    std::cout << "Adding edge: " << vertex1 << " -> " << vertex2 << std::endl;

    int index1 = std::find(vertices.begin(), vertices.end(), vertex1) - vertices.begin();
    int index2 = std::find(vertices.begin(), vertices.end(), vertex2) - vertices.begin();

    if (index1 >= numVertices || index2 >= numVertices) {
        std::cout << "Vertex does not exist!" << std::endl;
        return;
    }
    if (vertex1 == vertex2) {
        std::cout << "Self Loop Not Allowed!" << std::endl;
        return;
    }
    if (index1 < numVertices && index2 < numVertices && vertex1 != vertex2) {
        adjMatrix[index1][index2] = 1;
        numEdge++;
    }
}

void Graph::removeVertex(int vertex) {
    int index = std::find(vertices.begin(), vertices.end(), vertex) - vertices.begin();
    if (index >= numVertices) {
        std::cout << "Vertex does not exist!" << std::endl;
        return;
    }
    for (int i = 0; i < numVertices; ++i) {
        if (adjMatrix[index][i] == 1 || adjMatrix[i][index] == 1) {
            std::cout << "First remove edges connected to vertex " << vertex << std::endl;
            return;
        }
    }
    adjMatrix.erase(adjMatrix.begin() + index);
    for (auto& row : adjMatrix) {
        row.erase(row.begin() + index);
    }
    vertices.erase(vertices.begin() + index);
    numVertices--;
}

void Graph::removeEdge(int vertex1, int vertex2) {
    int index1 = std::find(vertices.begin(), vertices.end(), vertex1) - vertices.begin();
    int index2 = std::find(vertices.begin(), vertices.end(), vertex2) - vertices.begin();

    if (index1 >= numVertices || index2 >= numVertices) {
        std::cout << "Vertex does not exist!" << std::endl;
        return;
    }
    if (vertex1 == vertex2) {
        std::cout << "Edge Does Not Exist!" << std::endl;
        return;
    }
    if (index1 < numVertices && index2 < numVertices && vertex1 != vertex2) {
        adjMatrix[index1][index2] = 0;
        numEdge--;
    }
}

int Graph::getNumVertices() {
    if(numVertices == 0){
        std::cout << "Vertex Does Not Exist!";
        return 0;
    } else {
        return numVertices;
    }
}

void Graph::printGraph() const {
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            std::cout << adjMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int Graph::numEdges() const {
    int count = 0;
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            if (adjMatrix[i][j] == 1) {
                ++count;
            }
        }
    }
    return count;
}

int Graph::indegree(int vertex) const {
    int index = std::find(vertices.begin(), vertices.end(), vertex) - vertices.begin();
    if (index >= numVertices) {
        std::cerr << "Vertex does not exist!" << std::endl;
        return -1;
    }
    int count = 0;
    for (int i = 0; i < numVertices; ++i) {
        if (adjMatrix[i][index] != 0) {
            ++count;
        }
    }
    return count;
}

int Graph::outdegree(int vertex) const {
    int index = std::find(vertices.begin(), vertices.end(), vertex) - vertices.begin();
    if (index >= numVertices) {
        std::cerr << "Vertex does not exist!" << std::endl;
        return -1;
    }
    int count = 0;
    for (int i = 0; i < numVertices; ++i) {
        if (adjMatrix[index][i] != 0) {
            ++count;
        }
    }
    return count;
}

int Graph::degree(int vertex) const {
    int out = outdegree(vertex);
    int in = indegree(vertex);
    if (out == -1 || in == -1) {
        return -1; // Vertex does not exist
    }
    return out + in;
}

std::vector<int> Graph::neighbours(int vertex) const {
    int index = std::find(vertices.begin(), vertices.end(), vertex) - vertices.begin();
    if (index >= numVertices) {
        std::cerr << "Vertex does not exist!" << std::endl;
        return {};
    }
    std::vector<int> neighbors;
    for (int i = 0; i < numVertices; ++i) {
        if (adjMatrix[index][i] != 0) {
            neighbors.push_back(vertices[i]);
        }
    }
    return neighbors;
}

bool Graph::areNeighbours(int vertex1, int vertex2) const {
    int index1 = std::find(vertices.begin(), vertices.end(), vertex1) - vertices.begin();
    int index2 = std::find(vertices.begin(), vertices.end(), vertex2) - vertices.begin();

    if (index1 >= numVertices || index2 >= numVertices) {
        std::cerr << "Vertex does not exist!" << std::endl;
        return false;
    }
    return adjMatrix[index1][index2] != 0;
}

void Graph:: generateRandomGraph(int numVertices, int numEdges) {
    srand(time(0));
    for (int i = 0; i < numVertices; ++i) {
        addVertex(i);
    }
    for (int i = 0; i < numEdges; ++i) {
        int v1 = rand() % numVertices;
        int v2 = rand() % numVertices;
        addEdge(v1, v2);
    }
}


