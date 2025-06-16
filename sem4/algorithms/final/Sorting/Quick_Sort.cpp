#include <iostream>
using namespace std;

// Partitions subarray using Hoare's scheme with first element as pivot
// Time Complexity: Θ(n)
// Space Complexity: Θ(1)
int Hoare_Partition(int A[], int l, int r) {
    int p = A[l];
    int i = l - 1;
    int j = r + 1;
    
    while (true) {
        do {
            i++;
        } while (A[i] < p);
        
        do {
            j--;
        } while (A[j] > p);
        
        if (i >= j) {
            return j;
        }
        swap(A[i], A[j]);
    }
}

// Sorts subarray using quicksort with Hoare's partition
// Time Complexity: Average Θ(n log n), Worst Θ(n²)
// Space Complexity: Average Θ(log n), Worst Θ(n)
void Quick_Sort(int A[], int l, int r) {
    if (l < r) {
        int s = Hoare_Partition(A, l, r);
        Quick_Sort(A, l, s);
        Quick_Sort(A, s + 1, r);
    }
}