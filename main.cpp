#include "graph.h"

int main(int argc, char **argv) {
    Graph G = path(200);
    for (uint8_t neighbor : G.neighbors(1)) {
        printf("neighbor: %d\n", neighbor);
    }
    return 0;
}
