#include<iostream>
#include "graph.h"	

int main(){
    Graph g;
    std::cout << "Graph is empty: " << g.isEmpty() << std::endl;

    std::cout << "Adding vertices 1, 2, 3" << std::endl;
    g.addVertex(1); 
    g.addVertex(2);
    g.addVertex(3);

    std::cout<<"\nGraph\n";
    g.printGraph();

    std::cout << "Adding edges 1->2, 2->3, 3->1" << std::endl;
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,1);

     std::cout<<"\nGraph\n";
    g.printGraph();

    std::cout << "Number of edges: " << g.numEdges() << std::endl;
    std::cout << "Indegree of vertex 1: " << g.indegree(1) << std::endl;
    std::cout << "Outdegree of vertex 1: " << g.outdegree(1) << std::endl;
    
    std::cout<<"\ndeleting edge 1->2\n";
    g.removeEdge(1,2);

     std::cout<<"\nGraph\n";
    g.printGraph();

    std::cout<<"\ndeleting vertex 2\n";
    g.removeVertex(2);

   std::cout<<"\nGraph\n";
    g.printGraph();
    return 0;
}