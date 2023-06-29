#ifndef GRAPH_H
#define GRAPH_H
#include <stdint.h>
#include <unordered_set>
#include <unordered_map>

// Adjacency set representation
class Graph {
public:
    std::unordered_map<uint8_t, std::unordered_set<uint8_t>> adjacency;

    std::unordered_set<uint8_t> vertices;

    Graph(uint8_t numVerts);

    Graph(std::unordered_map<uint8_t, std::unordered_set<uint8_t>> adjacency, std::unordered_set<uint8_t> vertices);

    Graph copy();

    void addEdge(uint8_t x, uint8_t y);

    std::unordered_set<uint8_t> neighbors(uint8_t v);

    uint8_t countComponents();

    void removeVertex(uint8_t v);
};

Graph path(uint8_t numVerts);

Graph cycle(uint8_t numVerts);

#endif
