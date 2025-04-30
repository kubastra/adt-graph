#include <chrono>
#include "graph.h"
#include <fstream>

#define REPEATS 10
#define MAX_ITER 10000
std::ofstream file("time.dat");

void test() {
    AdjacencyGraph graph;
    graph.addVertex(5);
    graph.addVertex(7);
    graph.addVertex(19);

    graph.print();

    graph.removeVertex(7);
    graph.print();
}

void time_measure() {
    AdjacencyGraph graph;
    graph.addVertex(0);

    for (int i = 1; i < MAX_ITER; i++) {
        auto dur = 0;
        graph.addVertex(i);
        for (int j = 0; j < REPEATS; j++) {
            auto start = std::chrono::high_resolution_clock::now();
            graph.addEdge(i, i - 1);
            auto end = std::chrono::high_resolution_clock::now();
            dur += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
            graph.removeEdge(i, i - 1);
        }
        dur = dur / REPEATS;

        file << i - 1 << " " << dur << "\n";
    }
}
int main(){

    if (!file.is_open()) {
        return -1;
    }

    time_measure();

    file.close();

    return 0;
}