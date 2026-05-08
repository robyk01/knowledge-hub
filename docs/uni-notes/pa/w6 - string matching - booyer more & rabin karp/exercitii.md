2. Compute the hashes of the pattern p as well as all hashes for substrings of length m of s for the following values: p = aba, s = aabbababbabab, q = 3.

q = 3
d = 2 (a, b)
hash = (d * hash + char_value) % q

p = "aba"
hash = 0
i = 0, 'a' = 0, hash = (0 * 2 + 0) % 3 = 0
i = 1, 'b' = 1, hash = (0 * 2 + 1) % 3 = 1
i = 2, 'a' = 0, hash = (1 * 2 + 0) % 3 = 2

s = "aabbababbabab"
0, "aab"