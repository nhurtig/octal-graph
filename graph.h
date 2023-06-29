#ifndef GRAPH_H
#define GRAPH_H
#include <stdint.h>
#include <unordered_set>

// Adjacency matrix representation
class Graph {
private:
    bool *adjacency;
    uint8_t numVerts;

public:
    Graph(uint8_t numVerts);
    
    ~Graph();

    void addEdge(uint8_t x, uint8_t y);

    std::unordered_set<uint8_t> neighbors(uint8_t v);
};

#endif