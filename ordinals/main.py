import json
import sys

BINOM_FILE = "binom.json"
PP_FILE = "pp.json"

ppMap = {}
binomMap = {}

def binom(n, k):
    if k == 0:
        return 1
    if n == 0:
        return 0
    tup = str((n, k))
    if tup in binomMap:
        return binomMap[tup]
    ans = binom(n - 1, k - 1) * n // k
    binomMap[tup] = ans
    return ans

def pp(p, a, d):
    if d == 0 and a >= 2:
        return 0
    if a == 0 and p == 0:
        return 1
    if a == 0 and p >= 1:
        return 0
    if d == 0 and a == 1 and p == 0:
        return 1
    if d == 0 and a == 1 and p >= 1:
        return 0
    if d == 1 and a >= 1 and a == p:
        return 1
    if d == 1 and a >= 1 and a != p:
        return 0
    if p == 0:
        return 0
    else:
        tup = str((p, a, d))
        if tup in ppMap:
            return ppMap[tup]
        sum = 0
        for i in range(p):
            for j in range(1, a + 1):
                sum += binom(p - 1, i) * pp(i, j, d - 1) * pp(p - 1 - i, a - j, d)
        ppMap[tup] = sum
        return sum

def table(n, k):
    sum = 0
    for p in range(n * k + 1):
        sum += pp(p, n, k)
    return sum

def main():
    global ppMap
    global binomMap
    sumOfBoth = 0

    f = open(BINOM_FILE, 'r')
    binomMap = json.load(f)
    f.close()
    f = open(PP_FILE, 'r')
    ppMap = json.load(f)
    f.close()

    f = open('back'+BINOM_FILE, 'w+')
    json.dump(binomMap, f)
    f.flush()
    f.close()
    f = open('back'+PP_FILE, 'w+')
    json.dump(ppMap, f)
    f.flush()
    f.close()

    while True:
        for n in range(sumOfBoth + 1):
            ans = table(n, sumOfBoth - n)
            # print("T(a={}, d={}) = {}".format(n, sumOfBoth - n, ans))
            print(f"{ans},",end="")
            # sys.stdout.flush()
            # f = open(BINOM_FILE, 'w+')
            # json.dump(binomMap, f)
            # f.flush()
            # f.close()
            # f = open(PP_FILE, 'w+')
            # json.dump(ppMap, f)
            # f.flush()
            # f.close()
        sumOfBoth += 1
        if sumOfBoth > 15:
            print()
            break

if __name__ == "__main__":
    main()
