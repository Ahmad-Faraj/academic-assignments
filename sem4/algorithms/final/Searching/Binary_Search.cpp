// Searches for K in sorted array A using binary search
// Time Complexity: Θ(log n)
// Space Complexity: Θ(1)
int binarySearch(int A[], int n, int K) {
    int l = 0;
    int r = n - 1;
    
    while (l <= r) {
        int m = l + (r - l) / 2;  // Prevents potential overflow
        
        if (K == A[m]) {
            return m;  // Key found
        }
        else if (K < A[m]) {
            r = m - 1;  // Search left half
        }
        else {
            l = m + 1;  // Search right half
        }
    }
    return -1;  // Key not found
}