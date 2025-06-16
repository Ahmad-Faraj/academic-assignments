// Computes GCD using Euclid's algorithm (recursive)
// Time Complexity: O(log min(m,n))
// Space Complexity: O(log min(m,n)) due to recursion stack
int GCD(int m, int n) {
    if (n == 0) return m;
    return GCD(n, m % n);
}