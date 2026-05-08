1. Give a non-deterministic polynomial-time algorithm for the following computational prob-
lems:

(a) SUBSET-SUM;
(b) VERTEX-COVER;
(c) 3-COLORABILITY;
(d) HAMILTONIAN-PATH;
(e) HAMILTONIAN-CYCLE;
(f) GRAPH ISOMORPHISM.
2. Prove that the 2-colorability problem is in P.
3. Prove that the 2-SAT problem is in P.


##### Subset Sum
To make a non-deterministic algorithm we need to consider 2 parts:
- Guess (non-deterministic - exponential): we choose a random subset from the array. 2^n possibilities
- Verify (deterministic - polynomial): we calculate the sum of chosen elements and verify if it's equal to the target sum
Time complexity: O(n) - polynomial time

**Solution**: We can do the guessing part by using bitmaks.
Each bit represents the presence of a number in the subset
Array:    [3,   5,  17,  20,  4]
Index:     0    1   2    3   4
Bitmask:   0    0   0    0   0   = {} (empty)
Bitmask:   0    0   0    0   1   = {4}
Bitmask:   0    0   0    1   0   = {20}
Bitmask:   0    0   0    1   1   = {20, 4}
Bitmask:   1    0   0    1   0   = {3, 20}

Left shift moves bits to the left. In this context we can use 
if (mask & (1 << i))  // Verify if ith bit is in the mask

for (int mask = 0; mask < (1 << n); mask++) // Iterate through all possiblities

**Example** 
Array:    [3,   5,  17,  20,  4]
n = 10

First for loop goes from 0 to 1023 (2^n = 2^10 = 1024 and with left shift: 1023)
mask = 0 (binary: 000000)
    Second for loop goes from 0 to 9
    i = 0: 0 & (1 << 0) = 0 & 1 = 0 -> no bit is set
    i = 1: 0 & (1 << 1) = 0 & 2 = 0 -> no bit is set



