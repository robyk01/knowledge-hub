What is the decision problem corresponding to the knapsack problem?

### Optimization Problem
Input: n, v[0..n-1], w[0..n-1], W, all natural numbers
Knapsack capacity: W
Question: What is the maximum value you can put in the sack without exceeding W?
Output: p[0..n-1], p[i] in {0, 1}, each i in (0,n-1)

### Decision Problem
Input: n objects with a weight w_i and value v_i
Knapsack capacity: W
Target: value V
Question: Is there a subset S so that:
    sum w_i <= W and sum v_i >= V
Output: Yes or No

1. The decision problem is in NP
   If the answer is yes, we can verify in polynomial time by just adding weights and values.
2. The decision problem is NP Hard
   We can reduce with subset-sum (which is known as NP Hard)

### Reduction to subset sum
Input: array S = {a1, a2, a3.. an}, target T
Question: is there a subset with sum = target?

For each number a_i:
- weight w_i = a_i
- value v_i = a_i
- W = T
- V = T

Is there a subset with sum = target == is there a subset with weight <= T and value >= T

### Example
S = {3, 5, 7, 2}
Target T = 10
Question: is there a subset with sum = 10?
Output: yes: 3 + 7 = 10 or 5 + 2 + 3 = 10

For each a_i from S, we instantiate to knapsack problem:
    a_1 = 3  ->  w_1 = 3, v_1 = 3
    a_2 = 5  ->  w_2 = 5, v_2 = 5
    a_3 = 7  ->  w_3 = 7, v_3 = 7
    a_4 = 2  ->  w_4 = 2, v_4 = 2

    W = T = 10
    V = T = 10

    Knapsack Question: is there a subset with W <= 10 and V >= 10

    Subset {3, 7}
    - subset-sum: sum = 3 + 7 = 10
    - knapsack: weight = 3 + 7 = 10
                value = 3 + 7 = 10
    so weight = suma = T <= T
    and value = suma = T >= T


### Proof
- if there is a subset S which satisfies knapsack (weight <= W and value >= V) then the same subset satisfies subset sum
- if subset sum has no solutions, neither does knapsack

Given Subset Sum: S = {a1, a2, .. an}, target = T
Instantiate knapsack
    for each a_i: w_i = a_i, v_i = a_i
    W = T, V = T

If Subset Smm has a solution:
    Let X ⊆ S be a subset with sum(a_i for i ∈ X) = T
    Then for this same subset X in knapsack:
    - weight: sum w_i = sum a_i <= W = T
    - value: sum v_i = sum a_i >= V = T
Therefore X is a valid knapsack solution

If knapsack has a solution:
    Let X ⊆ S be a subset such that:
    - sum w_i <= W
    - sum v_i >= V

    Since w_i = v_i for all i, we haveL
    - sum a_i <= T
    - sum a_i >= T

    The only possibility is sum a_i = T
Therefore X is a valid subset sum solution with sum = T

If there is no solution in subset sum:
    Subset Sum has solution  ⟹  Knapsack has solution
    Knapsack has solution    ⟹  Subset Sum has solution

    From this implications it results that:
    Subset Sum no solution   ⟹  Knapsack no solution
    Knapsack no solution     ⟹  Subset Sum no solution









