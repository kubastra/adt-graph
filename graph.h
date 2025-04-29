#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <iostream>

class AdjacencyGraph {
private:
    std::vector<std::vector<int>> adjaMatrix;
    std::vector<int> vertexValues;

public:

    void addVertex(int vertex){
        int newSize = adjaMatrix.size() + 1;
        adjaMatrix.push_back(std::vector<int>(newSize));

        for (int i = 0; i < newSize - 1; i++) {
            adjaMatrix[i].push_back(0);
        }

        vertexValues.push_back(vertex);
    }

    void removeVertex(int vertex) {

    }

    void print() {

        std::cout << "    ";
        for (int val : vertexValues) {
            std::cout << val << " ";
        }
        std::cout << std::endl;

        for (size_t i = 0; i < adjaMatrix.size(); ++i) {
            std::cout << vertexValues[i] << " ";
            if (vertexValues[i] < 10) std::cout << " ";

            for (size_t j = 0; j < adjaMatrix[i].size(); ++j) {
                std::cout << " " << adjaMatrix[i][j];
            }
            std::cout << std::endl;
        }
    }

};

#endif
