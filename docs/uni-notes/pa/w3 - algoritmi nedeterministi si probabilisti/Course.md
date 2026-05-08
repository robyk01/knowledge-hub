# Nondeterministic and Probabilistic Algorithms - Summary

## 1. Nondeterministic Algorithms

### Definition
An algorithm is **nondeterministic** if it contains instructions whose result is not uniquely determined, but a value from a finite set of possible values.

### Key Characteristics
- **Multiple execution paths**: Unlike deterministic algorithms with a single execution path, nondeterministic algorithms can explore multiple paths simultaneously
- **Unrestricted parallelism**: Each possible execution path runs simultaneously (with each path being deterministic)
- **Angelic execution**: The algorithm "guesses" the execution path that leads to the correct result

### Core Operations
1. **choose x from A**: Creates a copy of the algorithm for every value in set A, all running independently and simultaneously
2. **success**: Ends execution of current path AND the entire algorithm (all other paths terminate)
3. **failure**: Terminates only the current execution path; other paths continue

### Two-Phase Structure
1. **Guessing phase**: Nondeterministically chooses (guesses) a solution
2. **Verification phase**: Checks correctness of the guessed solution (typically in polynomial time)

### Example
```
choose x from {2,3,4}
if x MOD 2 = 0 then
    success
else
    failure
```
Result: **Success** (because x=2 and x=4 exist)

### Key Theorem
For any nondeterministic algorithm A, there exists an equivalent deterministic algorithm B with:
$$T_B(n) = O(2^{T_A(n)})$$

---

## 2. Probabilistic (Randomized) Algorithms

### Definition
**Probabilistic algorithms** incorporate randomness into their decision-making process to improve efficiency, simplicity, or robustness. They have access to a stream of random bits for making random choices.

### Main Advantages
1. **Efficiency**: Execution time/space often smaller than best known deterministic algorithms
   - Example: Miller-Rabin primality test vs. AKS (O(log¹² n))
2. **Simplicity**: Usually much simpler to understand and implement
3. **Robustness**: Convert naive deterministic algorithms with bad worst-case behavior into algorithms that perform well with high probability

### Two Main Classes

#### Las Vegas Algorithms
- **Always produce correct results**
- Variable running time depending on random choices
- Example: Randomized QuickSort
- Trade-off: Correctness is guaranteed, but execution time varies
- Used when exact solutions are required

#### Monte Carlo Algorithms
- **Fixed running time**
- May produce incorrect results with small probability
- Example: Randomized primality tests
- Trade-off: Time is bounded, but correctness is probabilistic
- Used when approximate or probabilistic solutions are acceptable

---

## 3. Random Variables and Expectation

### Random Variable Definition
A **discrete random variable X** is a function from sample space S to real numbers. For random variable X and real number x:

$$Pr\{X = x\} = \sum_{s \in S | X(s) = x} Pr\{s\}$$

### Expected Value
The **expected value** (expectation/mean) of a discrete random variable X:

$$E[X] = \sum_x x \cdot Pr\{X = x\}$$

For natural numbers:
$$E[X] = \sum_{i=1}^{\infty} Pr\{X \geq i\}$$

### Properties
- $E[X + Y] = E[X] + E[Y]$ (linearity of expectation)
- $E[X \cdot Y] = E[X] \cdot E[Y]$ (when X and Y are independent)

---

## 4. Las Vegas Algorithms: QuickSort

### QuickSort Overview
Divide-and-conquer algorithm with three steps:

1. **Divide**: Partition array into two subarrays around pivot
2. **Conquer**: Recursively sort both subarrays
3. **Combine**: Already sorted, no work needed

### Complexity Analysis

**Worst-case partitioning** (always split into n-1 and 0):
$$T(n) = T(n-1) + \Theta(n) = \Theta(n^2)$$

**Best-case partitioning** (balanced split):
$$T(n) = 2T(n/2) + \Theta(n) = \Theta(n \log n)$$

### Randomized QuickSort
**Key improvement**: Randomly choose the pivot element instead of always using the rightmost element

```
Randomized-Partition(A, p, r):
    i ← Random(p, r)
    Swap A[r] and A[i]
    return Partition(A, p, r)
```

### Time Analysis
Using indicator random variable for comparisons:
$$X_{ij} = \begin{cases} 1 & \text{if } i\text{-th and } j\text{-th elements compared} \\ 0 & \text{otherwise} \end{cases}$$

Total comparisons:
$$C(n) = \sum_{i=1}^{n-1} \sum_{j=i+1}^{n} X_{ij}$$

**Probability two elements are compared**:
$$p_{ij} = \frac{2}{j + 1 - i}$$

**Expected comparisons**:
$$E[C(n)] = \sum_{i=1}^{n-1} \sum_{j=i+1}^{n} \frac{2}{j + 1 - i} = 2(n-1)H_n$$

Since $H_n = O(\log n)$, the expected running time is:
$$\boxed{E[T(n)] = O(n \log n)}$$

---

## 5. Monte Carlo Algorithms: Primality Testing

### Problem Statement
**PRIMES**: Given number k ∈ ℕ, determine if it's prime

### Naive Approach
```
IsPrime(k):
    if k ≤ 1 return false
    for i ← 2 to √k
        if k mod i = 0 return false
    return true
```
Complexity: **O(√k)**

### Mathematical Tools

#### Legendre Symbol
Determines if a is a quadratic residue modulo odd prime p:

$$\left(\frac{a}{p}\right) = \begin{cases} 
1 & \text{if } a \text{ is QR mod } p \text{ and } a \not\equiv 0 \pmod{p} \\
-1 & \text{if } a \text{ is non-QR mod } p \\
0 & \text{if } a \equiv 0 \pmod{p}
\end{cases}$$

**Key Property - Euler's Criterion**:
$$\left(\frac{a}{p}\right) \equiv a^{(p-1)/2} \pmod{p}$$

**Quadratic Reciprocity** (p, q distinct odd primes):
$$\left(\frac{a}{p}\right) = (-1)^{\frac{(a-1)(p-1)}{4}} \left(\frac{p}{a}\right)$$

#### Jacobi Symbol
Generalization of Legendre symbol to composite numbers n:

$$\left(\frac{a}{n}\right) = \left(\frac{a}{p_1}\right)^{e_1} \times \left(\frac{a}{p_2}\right)^{e_2} \times \cdots \times \left(\frac{a}{p_k}\right)^{e_k}$$

where $n = p_1^{e_1} p_2^{e_2} \cdots p_k^{e_k}$

**Key advantage**: Can be computed efficiently without factoring n

---

## 6. Comparison Table

| Feature | Deterministic | Nondeterministic | Probabilistic |
|---------|---------------|------------------|---------------|
| **Execution Path** | Single, well-defined | Multiple possible paths | Random choices at decision points |
| **Same Input Output** | Always the same | May vary based on choices | May vary based on random bits |
| **Correctness** | Always correct | Always correct (right path) | Variable (Las Vegas vs Monte Carlo) |
| **Runtime** | Deterministic | Variable (best path) | Variable (Las Vegas) or Fixed (Monte Carlo) |
| **Randomness** | None | Implicit (guessing) | Explicit (random number generator) |

---

## Key Takeaways

1. **Nondeterministic algorithms** are theoretical models exploring multiple paths simultaneously; they can be converted to deterministic with exponential time cost
2. **Las Vegas algorithms** guarantee correctness but have variable runtime (QuickSort example)
3. **Monte Carlo algorithms** have fixed runtime but probabilistic correctness (Primality testing)
4. **Randomization** often dramatically improves practical performance despite similar worst-case complexity
5. **Linearity of expectation** is a powerful tool for analyzing randomized algorithms
6. **Mathematical tools** like Legendre/Jacobi symbols enable efficient probabilistic algorithms for number theory problems