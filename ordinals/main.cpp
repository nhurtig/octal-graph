#include <iostream>
#include <map>
#include <tuple>
#include <limits.h>

#define num unsigned long long int
#define snum unsigned int

std::map<std::tuple<snum, snum, snum>, num> ppMap;
std::map<std::tuple<snum, snum>, num> binomMap;

num binom(num n, num k) {
    if (k == 0)
        return 1;
    if (n == 0)
        return 0;
    std::tuple<num, num> tup = std::make_tuple(n, k);
    if (binomMap.count(tup)) {
        return binomMap[tup];
    }
    // printf("%llu, %llu\n", n, k);

    num ans = binom(n - 1, k - 1) * n / k;
    binomMap[tup] = ans;
    return ans;
}

num pp(num p, num a, num d) {
    if (d == 0 && a >= 2)
        return 0;
    if (a == 0 && p == 0)
        return 1;
    if (a == 0 && p >= 1)
        return 0;
    if (d == 0 && a == 1 && p == 0)
        return 1;
    if (d == 0 && a == 1 && p >= 1)
        return 0;
    if (d == 1 && a >= 1 && a == p)
        return 1;
    if (d == 1 && a >= 1 && a != p)
        return 0;
    if (p == 0) {
        return 0;
    }
    else {
        std::tuple<num, num, num> tup = std::make_tuple(p, a, d);
        if (ppMap.count(tup)) {
            return ppMap[tup];
        }

        // printf("%llu,%llu,%llu\n", p, a, d);
        num sum = 0;
        for (num i = 0; i <= p - 1; i++) {
            for (num j = 1; j <= a; j++) {
                sum += binom(p - 1, i) * pp(i, j, d - 1) * pp(p - 1 - i, a - j, d);
            }
        }
        ppMap[tup] = sum;
        return sum;
    }
}

num table(snum n, snum k) {
    num sum = 0;
    for (snum p = 0; p <= n * k; p++) {
        sum += pp(p, n, k);
    }
    return sum;
}

int main() {
    ppMap = std::map<std::tuple<snum, snum, snum>, num>();
    binomMap = std::map<std::tuple<snum, snum>, num>();
    snum sumOfBoth = 0;
    while (1) {
        for (snum n = 0; n <= sumOfBoth; n++) {
            num ans = table(n, sumOfBoth-n);
            printf("T(a=%u, d=%u) = %llu\n", n, sumOfBoth-n, ans);
            printf("%llu\n", ULLONG_MAX);
            printf("%llu\n", ans);
        }
        sumOfBoth++;
    }
    return 0;
}
