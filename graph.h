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
        int index = getIndex(vertex);

        if (index == -1) return;

        adjaMatrix.erase(adjaMatrix.begin() + index);

        for (auto &row : adjaMatrix) {
            row.erase(row.begin() + index);
        }

        vertexValues.erase(vertexValues.begin() + index);

    }

    bool adjacent(int x, int y) { return adjaMatrix[x][y] != 0; }

    std::vector<int> neighbours(int vertex) {
        std::vector<int> neighbours;
        int index = getIndex(vertex);

        for (int i = 0; i < adjaMatrix.size(); i++) {
            if (adjaMatrix[i][index] == 1) {
                neighbours.push_back(vertexValues[i]);
            }
        }
        return neighbours;
    }
    int getIndex(int vertex) {
        int index = -1;
        for (int i = 0; i < vertexValues.size(); i++) {
            if (vertexValues[i] == vertex) {
                index = i;
                return index;
            }
        }
    }
    void addEdge(int x, int y) {
        int index_x = getIndex(x);
        int index_y = getIndex(y);

        adjaMatrix[index_x][index_y] = 1;
        adjaMatrix[index_y][index_x] = 1;
    }

    void removeEdge(int x, int y) {
        int index_x = getIndex(x);
        int index_y = getIndex(y);

        adjaMatrix[index_x][index_y] = 0;
        adjaMatrix[index_y][index_x] = 0;
    }

    int getEdgeValue(int x, int y) {
        int index_x = getIndex(x);
        int index_y = getIndex(y);

        return adjaMatrix[index_x][index_y];
    }

    void setEdgeValue(int x, int y) {
        int index_x = getIndex(x);
        int index_y = getIndex(y);
        adjaMatrix[index_x][index_y] = 1;
        adjaMatrix[index_y][index_x] = 1;
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
