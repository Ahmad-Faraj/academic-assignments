// Finds largest value in array
// Time Complexity: Best/Average/Worst Case Θ(n)
// Space Complexity: Best/Average/Worst Case Θ(1)
int MaxElement(int A[], int n) {
    int maxval = A[0];
    for (int i = 1; i < n; ++i) {
        if (A[i] > maxval) {
            maxval = A[i];
        }
    }
    return maxval;
}