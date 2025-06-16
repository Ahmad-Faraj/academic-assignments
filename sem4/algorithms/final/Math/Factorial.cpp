// Computes n! recursively
// Time Complexity: Best/Average/Worst Case Θ(n)
// Space Complexity: Best/Average/Worst Case Θ(n) (due to recursion stack)
int Fact(int n) {
    if (n == 0) return 1;
    return Fact(n - 1) * n;
}