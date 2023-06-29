#ifndef GAME_TREE_H
#define GAME_TREE_H
#include "graph.h"

uint8_t mex(std::unordered_set<uint8_t>);

uint8_t nimber(Graph G, uint8_t *rules, uint8_t rulesLen);

std::unordered_set<uint8_t> nimber_set(Graph G, uint8_t *rules, uint8_t rulesLen, uint8_t *rulesOrig, uint8_t rulesLenOrig,
    std::unordered_set<uint8_t> can_remove, std::unordered_set<uint8_t> cant_remove, bool is_first);

uint8_t* copy_array(uint8_t *arr, uint8_t arrLen);

uint8_t sum_array(uint8_t *rules, uint8_t rulesLen);

#endif
