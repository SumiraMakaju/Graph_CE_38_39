#include <iostream>
#include <vector>
#include "graph.h"
 bool Graph :: isEmpty() {
      return numVertices == 0;
}

bool Graph :: isDirected(){
    if(numVertices == 0)
        std::cout << "Vertex Does Not Exist!";
    else
        return true;
}

void Graph :: addVertex() {
     numVertices++;
    int i;
    for (i = 1; i <= numVertices; ++i) {
        adjMatrix[i][numVertices] = 0;
        adjMatrix[numVertices][i] = 0;
    }
}

void Graph :: addEdge(int vertex1, int vertex2) {
    if ((vertex1 > numVertices) || (vertex2 > numVertices)) {
        std::cout << "Vertex does not exist!";
    }
    if (vertex1 == vertex2) {
        std::cout << "Self Loop Not Allowed!";
    }
    if((vertex1 <= numVertices) && (vertex2 <= numVertices) && vertex1 != vertex2) {
        adjMatrix[vertex2][vertex1] = 0;
        adjMatrix[vertex1][vertex2] = 1;
        numEdge++;
    }
}

void Graph::removeVertex(int vertex) {
    if (vertex > numVertices) {
        std::cout << "Vertex does not exist!" << std::endl;
        return;
    }
    for (int i = 0; i < numVertices; ++i) {
        if (adjMatrix[vertex-1][i] == 1 || adjMatrix[i][vertex-1] == 1) {
            std::cout << "First remove edges connected to vertex " << vertex << std::endl;
            return;
        }
    }
    adjMatrix.erase(adjMatrix.begin() + vertex - 1);
    for (auto& row : adjMatrix) {
        row.erase(row.begin() + vertex - 1);
    }
    numVertices--;
}

void Graph::removeEdge(int vertex1, int vertex2) {
     if((vertex1 > numVertices)  || (vertex2 > numVertices)){
        std::cout << "Vertex does not exist!";
    }
    if (vertex1 == vertex2) {
        std::cout << "Edge Does Not Exist!";
    }
    if((vertex1 <= numVertices) && (vertex2 <= numVertices) && vertex1 != vertex2) {
        adjMatrix[vertex2][vertex1] = 0;
        adjMatrix[vertex1][vertex2] = 0;
        numEdge--;
    }
}

int Graph::getNumVertices() {
    if(numVertices == 0){
        std::cout << "Vertex Does Not Exist!";
    }
    else{
        return(numVertices);
    }
}

