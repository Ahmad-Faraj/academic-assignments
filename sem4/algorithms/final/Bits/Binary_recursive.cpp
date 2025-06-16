// Counts bits in n's binary representation using recursion
// Time Complexity: Best/Average/Worst Case Θ(log n)
// Space Complexity: Best/Average/Worst Case Θ(log n) (due to recursion stack)
int Bin_Rec(int n) {
    if (n == 1) return 1;
    return Bin_Rec(n / 2) + 1;
}