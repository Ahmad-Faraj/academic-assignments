// Computes the nth Fibonacci number iteratively
// Time Complexity: Best/Average/Worst Case Θ(n)
// Space Complexity: Best/Average/Worst Case Θ(n)
int Fib(int n) {
    if (n <= 1) return n;
    
    int F[n+1];
    F[0] = 0;
    F[1] = 1;
    
    for (int i = 2; i <= n; i++) {
        F[i] = F[i-1] + F[i-2];
    }
    
    return F[n];
}