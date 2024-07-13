#pragma once
#include<vector>
class Graph{
    int numEdge=0, numInDegree=0, numOutDegree=0, degree=0;
        int adjMatrix[26][26];
    public:
        int numVertices;
       int check = false;
        std::vector<std::vector<int>> adjMatrix;
        std::vector<int>vertices;
        Graph(){}
        Graph(int v);
        ~Graph(){}

        bool isEmpty();
        bool isDirected();
        void addVertex();
        void addEdge(int vertex1, int vertex2);
        void removeVertex(int vertextoremove);
        void removeEdge(int vertex1, int vertex2);
        int getNumVertices();

};
