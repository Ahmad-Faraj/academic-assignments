# Gaussian Elimination Pseudocode Analysis

## Problem Statement

Consider the following pseudocode for Gaussian Elimination (GE):

```
ALGORITHM GE(A[0..n−1, 0..n])
// Input: An n × (n + 1) matrix A[0..n−1, 0..n] of real numbers

for i ← 0 to n − 2 do
    for j ← i + 1 to n − 1 do
        for k ← i to n do
            A[j, k] ← A[j, k] − A[i, k] * A[j, i] / A[i, i]
```

### Questions

**a.** Find the time efficiency class of this algorithm.  
**b.** What glaring inefficiency does this pseudocode contain and how can it be eliminated to speed the algorithm up?

---

## Solution

### a. Time Complexity Analysis

We are given three nested loops:

- Outer loop (`i`): runs from `0` to `n−2` → **(n−1)** iterations  
- Middle loop (`j`): runs from `i+1` to `n−1` → **(n−i−1)** iterations  
- Inner loop (`k`): runs from `i` to `n` → **(n−i+1)** iterations

We calculate the total number of basic operations as follows:

#### Total Work:

We can represent the total operations as:

```
T(n) = ∑_{i=0}^{n-2} ∑_{j=i+1}^{n-1} ∑_{k=i}^{n} O(1)
```

For a fixed `i`:
- Middle loop: `(n - i - 1)` iterations
- Inner loop: `(n - i + 1)` iterations

Hence:

```
T(n) = ∑_{i=0}^{n-2} (n - i - 1)(n - i + 1)
```

Let `m = n - i`, then the sum becomes:

```
T(n) = ∑_{m=2}^{n} (m - 1)(m + 1) = ∑_{m=2}^{n} (m^2 - 1)
```

We now evaluate the sum:

```
T(n) = (∑_{m=1}^{n} m^2 - 1^2) - (n - 1)
     = (n(n+1)(2n+1)/6 - 1) - (n - 1)
```

This simplifies to:

```
T(n) = Θ(n^3)
```

### ✅ Final Answer (a): Θ(n³)

---

### b. Inefficiency and Optimization

#### Observed Inefficiency

In the innermost loop:

```
A[j, k] ← A[j, k] − A[i, k] * A[j, i] / A[i, i]
```

The expression `A[j, i] / A[i, i]` is:

- Independent of `k`
- Recomputed in **every iteration of the inner loop**

This leads to unnecessary division and multiplication operations.

#### Optimized Version

We eliminate redundancy by computing the division result once:

```
factor ← A[j, i] / A[i, i]
for k ← i to n do
    A[j, k] ← A[j, k] − A[i, k] * factor
```

#### Result

- Reduces the number of operations
- Improves practical performance
- **Asymptotic time remains** Θ(n³)

---

## Summary

| Item                | Description                                                  |
|---------------------|--------------------------------------------------------------|
| **Time Complexity** | Θ(n³)                                                        |
| **Inefficiency**    | Repeated computation of `A[j, i] / A[i, i]` inside inner loop |
| **Optimization**    | Precompute the factor before the inner loop                 |
| **Result**          | Faster execution in practice, same asymptotic complexity     |
