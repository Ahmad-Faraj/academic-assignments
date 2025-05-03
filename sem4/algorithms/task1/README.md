# **Question 1: Computing \(2^n\) Recursively**

## **(a) Recursive Algorithm**
The given recurrence relation is:
\[
2^n = 2^{n-1} + 2^{n-1}
\]
This suggests the following recursive algorithm:

### **Pseudo Code**
```plaintext
function power_of_2(n):
    if n == 0:
        return 1
    return power_of_2(n - 1) + power_of_2(n - 1)
```
The base case is \(2^0 = 1\), and otherwise, the function makes two recursive calls.

---

## **(b) Recurrence Relation for Additions**
Each function call makes **two** recursive calls and adds their results. If \(T(n)\) is the number of additions:

\[
T(n) = 2T(n-1) + 1
\]
Base case: \(T(0) = 0\) (since no addition is needed for \(2^0\)).

Solving this recurrence using expansion:

\[
T(n) = 2T(n-1) + 1
\]
\[
= 2(2T(n-2) + 1) + 1 = 4T(n-2) + 2 + 1
\]
\[
= 8T(n-3) + 4 + 2 + 1
\]

Expanding further:

\[
T(n) = 2^kT(n-k) + (2^k - 1)
\]

Setting \(k = n\), we get:

\[
T(n) = 2^n T(0) + (2^n - 1) = 2^n - 1
\]

So the number of additions is **\(2^n - 1\)**.

---

## **(c) Recursive Call Tree**
For \( n = 3 \), the call tree looks like:

```
               power_of_2(3)
              /            \
      power_of_2(2)      power_of_2(2)
      /        \         /        \
power_of_2(1) power_of_2(1) power_of_2(1) power_of_2(1)
   /    \      /     \       /    \      /     \
  1      1    1       1     1      1    1       1
```

The number of calls is:

\[
2^{n+1} - 1
\]

For \(n=3\), this is **\(2^4 - 1 = 15\)**.

---

## **(d) Is this a good algorithm?**
No, because:
1. **Exponential Time Complexity**: \(O(2^n)\) is too slow.
2. **Repeated Computation**: The function recomputes values for the same \(n\) multiple times.

---

## **Optimization with Dynamic Programming**
From competitive programming, I know DP avoids repeated calculations by storing results. A better approach:

### **Top-down (Memoization)**
```plaintext
function power_of_2(n, memo):
    if n == 0:
        return 1
    if memo[n] is not None:
        return memo[n]
    memo[n] = 2 * power_of_2(n-1, memo)
    return memo[n]
```
### **Bottom-up (Iterative DP)**
```plaintext
function power_of_2(n):
    result = 1
    for i from 1 to n:
        result *= 2
    return result
```
Now the time complexity is **\(O(n)\) for memoization** and **\(O(1)\) for the iterative version**.

---

# **Question 2: Understanding the Recursive Algorithm**

## **(a) What does this algorithm compute?**
The given algorithm is:

```plaintext
function Riddle(A[0..n-1]):
    if n == 1:
        return A[0]
    temp = Riddle(A[0..n-2])
    if temp ≤ A[n-1]:
        return temp
    else:
        return A[n-1]
```
This function **returns the minimum value in the array**. It recursively finds the minimum in the first \(n-1\) elements and compares it with \(A[n-1]\).

---

## **(b) Recurrence Relation**
Let \(T(n)\) be the number of comparisons made:

\[
T(n) = T(n-1) + 1
\]

Base case: \(T(1) = 0\) (no comparisons for a single element).

Solving this recurrence:

\[
T(n) = T(n-1) + 1
\]

\[
= (T(n-2) + 1) + 1
\]

\[
= (T(n-3) + 1) + 1 + 1
\]

Expanding:

\[
T(n) = T(1) + (n-1) = 0 + (n-1) = n-1
\]

So, the algorithm performs **\(O(n)\) comparisons**.

---

## **(c) Recursive Call Tree**
For \( A = [4, 2, 7, 1] \), the recursion tree looks like:

```
               Riddle([4,2,7,1])
                     |
             Riddle([4,2,7])
                     |
             Riddle([4,2])
                     |
             Riddle([4])
```

Each call reduces the array size by one, leading to \(O(n)\) calls.

---

## **(d) Optimizing with Dynamic Programming**
DP is **not needed** here because:
1. **Each subproblem depends only on the previous subproblem** (linear dependency).
2. **There are no overlapping subproblems** like Fibonacci.

A better approach is using **iteration**:

### **Iterative Approach**
```plaintext
function min_element(A):
    min_val = A[0]
    for i from 1 to n-1:
        if A[i] < min_val:
            min_val = A[i]
    return min_val
```
This runs in **\(O(n)\)** time but avoids recursive overhead.
