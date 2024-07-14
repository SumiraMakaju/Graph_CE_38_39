#pragma once
#include<vector>
class Graph{
    int numEdge=0, numInDegree=0, numOutDegree=0;
    int vertexDegree=0;
        //int adjMatrix[26][26];
    public:
        int numVertices;
       int check = false;
        std::vector<std::vector<int>> adjMatrix;
        std::vector<int>vertices;
        Graph();
        
        ~Graph(){}

        bool isEmpty();
        bool isDirected();
        void addVertex(int vedrtex);
        void addEdge(int vertex1, int vertex2);
        void removeVertex(int vertextoremove);
        void removeEdge(int vertex1, int vertex2);
        int getNumVertices();
        void printGraph() const;
    int numEdges() const;
    int indegree(int vertex) const;
    int outdegree(int vertex) const;
    int degree(int vertex) const;
    std::vector<int> neighbours(int vertex) const;
    bool areNeighbours(int vertex1, int vertex2) const;

  //bonus  
void generateRandomGraph(int numVertices, int numEdges);

};
