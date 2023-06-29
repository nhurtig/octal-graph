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

Graph::Graph(std::unordered_map<uint8_t, std::unordered_set<uint8_t>> adjacency, std::unordered_set<uint8_t> vertices) {
    this->adjacency = adjacency;
    this->vertices = vertices;
}


Graph Graph::copy() {
    std::unordered_map<uint8_t, std::unordered_set<uint8_t>> adjacencyPrime = std::unordered_map<uint8_t, std::unordered_set<uint8_t>>();
    for (const auto& pair : this->adjacency) {
        std::unordered_set<uint8_t> adjPrime (pair.second.begin(), pair.second.end());
        adjacencyPrime[pair.first] = adjPrime;
    }

    std::unordered_set<uint8_t> verticesPrime (this->vertices.begin(), this->vertices.end());

    return Graph(adjacencyPrime, verticesPrime);
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

uint8_t Graph::countComponents() {
    uint8_t ncomps = 0;
    std::unordered_set<uint8_t> unvisited (this->vertices.begin(), this->vertices.end());
    std::unordered_set<uint8_t> queued;
    while (unvisited.size()) {
        ncomps++;
        uint8_t v = *unvisited.begin();
        unvisited.erase(v);
        queued = std::unordered_set<uint8_t>{v};
        while (queued.size()) {
            v = *queued.begin();
            queued.erase(v);
            for (uint8_t y : this->neighbors(v)) {
                if (unvisited.count(y)) {
                    unvisited.erase(y);
                    queued.insert(y);
                }
            }
        }
    }

    return ncomps;
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
