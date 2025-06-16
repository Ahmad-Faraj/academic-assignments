#include <iostream>
using namespace std;

// Merges two sorted arrays into one sorted array
// Time Complexity: Θ(n)
// Space Complexity: Θ(1) (not counting input arrays)
void merge(int B[], int p, int C[], int q, int A[]) {
    int i = 0, j = 0, k = 0;
    
    while (i < p && j < q) {
        if (B[i] <= C[j]) {
            A[k++] = B[i++];
        } else {
            A[k++] = C[j++];
        }
    }
    
    while (i < p) {
        A[k++] = B[i++];
    }
    
    while (j < q) {
        A[k++] = C[j++];
    }
}

// Sorts array using recursive mergesort
// Time Complexity: Θ(n log n)
// Space Complexity: Θ(n)
void Merge_Sort(int A[], int n) {
    if (n > 1) {
        int mid = n / 2;
        int* B = new int[mid];
        int* C = new int[n - mid];
        
        for (int i = 0; i < mid; i++) {
            B[i] = A[i];
        }
        for (int i = mid; i < n; i++) {
            C[i - mid] = A[i];
        }
        
        Merge_Sort(B, mid);
        Merge_Sort(C, n - mid);
        merge(B, mid, C, n - mid, A);
        
        delete[] B;
        delete[] C;
    }
}