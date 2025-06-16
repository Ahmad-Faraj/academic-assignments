// Computes GCD using Euclid's algorithm (iterative)
// Time Complexity: O(log min(m,n))
// Space Complexity: O(1)
int GCD(int m, int n) {
    while (n != 0) {
        int r = m % n;
        m = n;
        n = r;
    }
    return m;
}