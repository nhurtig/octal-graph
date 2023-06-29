#include "graph.h"
#include <string.h>

Graph::Graph(uint8_t numVerts) {
    this->numVerts = numVerts;
    this->adjacency = (bool*) malloc(sizeof(bool)*numVerts*numVerts);
    memset(this->adjacency, 0, sizeof(bool)*numVerts*numVerts);
}

Graph::~Graph() {
    free(this->adjacency);
}

void Graph::addEdge(uint8_t x, uint8_t y) {
    this->adjacency[x*numVerts+y] = 1;
    this->adjacency[y*numVerts+x] = 1;
}

std::unordered_set<uint8_t> Graph::neighbors(uint8_t v) {
    std::unordered_set<uint8_t> neighbors;
    for (int y = 0; y < this->numVerts; y++) {
        if (this->adjacency[v*numVerts+y]) {
            neighbors.insert(y);
        }
    }
    return neighbors;
}
