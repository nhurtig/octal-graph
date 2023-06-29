#include "graph.h"
#include <string.h>

Graph::Graph(uint8_t numVerts) {
    this->adjacency = std::unordered_map<uint8_t, std::unordered_set<uint8_t>>();
    this->vertices = std::unordered_set<uint8_t>();
    for (uint8_t v = 0; v < numVerts; v++) {
        this->adjacency[v] = std::unordered_set<uint8_t>();
        this->vertices.insert(v);
    }
}

void Graph::addEdge(uint8_t x, uint8_t y) {
    this->adjacency[x].insert(y);
    this->adjacency[y].insert(x);
}

std::unordered_set<uint8_t> Graph::neighbors(uint8_t v) {
    return this->adjacency[v];
}

void Graph::removeVertex(uint8_t v) {
    this->vertices.erase(v);
}

void Graph::removeVertices(std::unordered_set<uint8_t> V) {
    for (uint8_t v : V) {
        this->removeVertex(v);
    }
}

Graph path(uint8_t numVerts) {
    Graph path (numVerts);
    for (uint8_t i = 0; i < numVerts-1; i++) {
        path.addEdge(i, i+1);
    }
    return path;
}

Graph cycle(uint8_t numVerts) {
    Graph cycle = path(numVerts);
    cycle.addEdge(0, cycle.vertices.size() - 1);
    return cycle;
}
