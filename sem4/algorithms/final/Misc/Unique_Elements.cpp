// Checks if all array elements are distinct
// Time Complexity: Best/Average/Worst Case Θ(n²)
// Space Complexity: Best/Average/Worst Case Θ(1)
bool UniqueElements(double A[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (A[i] == A[j]) return false;
        }
    }
    return true;
}