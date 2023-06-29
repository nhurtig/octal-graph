#include "game_tree.h"
#include <cmath>

uint8_t nimber(Graph G, uint8_t *rules, uint8_t rulesLen) {
    return mex(nimber_set(G, copy_array(rules, rulesLen), rulesLen, rules, rulesLen, G.vertices, std::unordered_set<uint8_t>(), true));
}

std::unordered_set<uint8_t> nimber_set(Graph G, uint8_t *rules, uint8_t rulesLen, uint8_t *rulesOrig, uint8_t rulesLenOrig,
    std::unordered_set<uint8_t> can_remove, std::unordered_set<uint8_t> cant_remove, bool is_first) {

    std::unordered_set<uint8_t> nimbers_so_far = std::unordered_set<uint8_t>();
    if (!sum_array(rules, rulesLen)) { // no moves left
        return nimbers_so_far;
    }

    // otherwise, remove a vertex
    for (uint8_t v : can_remove) {
        Graph Gprime = G.copy();
        Gprime.removeVertex(v);
        uint8_t nComp = Gprime.countComponents();
        // is this a valid end to my turn?
        if ((nComp < 8) && ((1 << nComp) & rules[0])) {
            nimbers_so_far.insert(nimber(Gprime, rulesOrig, rulesLenOrig));
        }
        cant_remove.insert(v);

        std::unordered_set<uint8_t> cant_remove_prime (cant_remove.begin(), cant_remove.end());

        std::unordered_set<uint8_t> can_remove_prime;
        if (is_first) { // copy v's neighborhood
            std::unordered_set<uint8_t> vNeigh = G.neighbors(v);
            can_remove_prime = std::unordered_set<uint8_t>(vNeigh.begin(), vNeigh.end());
        } else { // extend with v's neighborhood
            can_remove_prime = std::unordered_set<uint8_t>(can_remove.begin(), can_remove.end());
            for (uint8_t n : G.neighbors(v)) {
                can_remove_prime.insert(n);
            }
        }
        
        // recurse
        uint8_t *rulesPrime = copy_array(rules+1, rulesLen-1);
        for (uint8_t nimber : nimber_set(G, rulesPrime, rulesLen-1, rulesOrig, rulesLenOrig, 
                                            can_remove_prime, cant_remove_prime, false)) {
            nimbers_so_far.insert(nimber);
        }
    }

    free(rules);
    return nimbers_so_far;
}

uint8_t* copy_array(uint8_t *arr, uint8_t arrLen) {
    uint8_t *arrPrime = (uint8_t*) malloc(sizeof(uint8_t)*arrLen);
    for (uint8_t i = 0; i < arrLen; i++) {
        arrPrime[i] = arr[i];
    }
    return arrPrime;
}

uint8_t sum_array(uint8_t *rules, uint8_t rulesLen) {
    uint8_t s = 0;
    for (uint8_t i = 0; i < rulesLen; i++) {
         s += rules[i];
    }
    return s;
}

uint8_t mex(std::unordered_set<uint8_t> S) {
    uint8_t i = 0;
    while(S.count(i)) {
        i++;
    }
    return i;
}
