#include "graph.h"
#include "game_tree.h"

int main(int argc, char **argv) {
    // 0.33
    uint8_t rulesLen = 2;
    uint8_t rules[rulesLen] = {3,3};

    for (uint8_t i = 0; i < 200; i++) {
        uint8_t nim = nimber(path(i), rules, rulesLen);
        printf("nimber: %d\n", nim);
    }
    return 0;
}
