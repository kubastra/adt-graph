#include "graph.h"

int main(){

    AdjacencyGraph graph;
    graph.addVertex(5);
    graph.addVertex(7);
    graph.addVertex(19);

    graph.print();

    graph.removeVertex(7);
    graph.print();
    return 0;
}