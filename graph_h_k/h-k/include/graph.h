#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

class Graph {
public:
    Graph(const std::vector<std::vector<int>>& adjacentmatrix);
    Graph(int numvertices);
    void printGraph() const;
    int numEdges() const;
    int indegree(int vertex) const;
    int outdegree(int vertex) const;
    int degree(int vertex) const;
    std::vector<int> neighbours(int vertex) const;
    bool areNeighbours(int vertex1, int vertex2) const;

private:
    std::vector<std::vector<int>> adjacentmatrix;
    int numvertices;
};

#endif
