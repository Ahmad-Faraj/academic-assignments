// Counts bits in n's binary form
// Time Complexity: Best/Average/Worst Case Θ(log n)
// Space Complexity: Best/Average/Worst Case Θ(1)
int Binary(int n) {
    int count = 1;
    while (n > 1) {
        count++;
        n = n / 2;
    }
    return count;
}