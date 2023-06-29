#include "graph.h"

int main(int argc, char **argv) {
    Graph G (3);
    G.addEdge(0, 1);
    G.addEdge(0, 2);
    for (uint8_t neighbor : G.neighbors(0)) {
        printf("neighbor: %d\n", neighbor);
    }
    return 0;
}
