// Searches for pattern P in text T using brute-force matching
// Time Complexity: Best Case Θ(n), Average/Worst Case Θ(n*m)
// Space Complexity: Best/Average/Worst Case Θ(1)
int String_Match(char T[], int n, char P[], int m) {
    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m && P[j] == T[i + j]) {
            j++;
        }
        if (j == m) return i;
    }
    return -1;
}