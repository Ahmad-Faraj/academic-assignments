#include <iostream>
using namespace std;

// Partitions subarray using Lomuto's scheme with first element as pivot
// Time Complexity: Θ(n)
// Space Complexity: Θ(1)
int lomuto_Partition(int A[], int l, int r) {
    int p = A[l];
    int s = l;
    for (int i = l + 1; i <= r; i++) {
        if (A[i] < p) {
            s++;
            swap(A[s], A[i]);
        }
    }
    swap(A[l], A[s]);
    return s;
}

// Finds k-th smallest element using quickselect algorithm
// Time Complexity: Average Θ(n), Worst Θ(n²)
// Space Complexity: Average Θ(log n), Worst Θ(n)
int quick_Select(int A[], int l, int r, int k) {
    if (l == r) return A[l];
    
    int s = lomuto_Partition(A, l, r);
    
    if (s == k - 1) {
        return A[s];
    }
    else if (s > k - 1) {
        return quick_Select(A, l, s - 1, k);
    }
    else {
        return quick_Select(A, s + 1, r, k);
    }
}