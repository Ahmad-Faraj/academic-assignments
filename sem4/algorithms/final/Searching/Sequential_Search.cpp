// Searches for key K in array A using sentinel technique
// Time Complexity: Best Case Θ(1), Average/Worst Case Θ(n)
// Space Complexity: Best/Average/Worst Case Θ(1)
int SequentialSearch2(int A[], int n, int K) {
    A[n] = K;  // Add sentinel
    int i = 0;
    while (A[i] != K) {
        i++;
    }
    if (i < n) return i;
    else return -1;
}