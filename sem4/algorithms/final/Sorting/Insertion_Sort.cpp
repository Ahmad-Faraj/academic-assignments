#include <iostream>
using namespace std;

// Sorts an array in non-decreasing order using insertion sort
// Time Complexity: Best Case Θ(n), Average/Worst Case Θ(n²)
// Space Complexity: Best/Average/Worst Case Θ(1)
void InsertionSort(int A[], int n) {
    for (int i = 1; i < n; i++) {
        int v = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > v) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;
    }
}