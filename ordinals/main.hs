pp p n k
  | n == 0 && k >= 2 = 0
  | k == 0 && p == 0 = 1
  | k == 0 && p >= 1 = 0
  | n == 0 && k == 1 && p == 0 = 1
  | n == 0 && k == 1 && p >= 1 = 0
  | n == 1 && k >= 1 && k == p = 1
  | n == 1 && k >= 1 && k /= p = 0
  | n >= 2 && k >= 1 = sum [binom (p-1) i * pp i (n-1) j * pp (p-1-i) n (k-j) | i <- [0..p-1], j <- [1..k]]
binom n 0 = 1
binom 0 k = 0
binom n k = binom (n-1) (k-1) * n `div` k
a364026 n k =
  sum [pp p n k | p <- [0..n*k]] -- Nathan Hurtig, Jul 01 2023