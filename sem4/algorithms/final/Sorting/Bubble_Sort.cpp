#include <iostream>
using namespace std;

// Sorts an array in non-decreasing order using naive bubble sort
// Time Complexity: Best/Average/Worst Case Θ(n²)
// Space Complexity: Best/Average/Worst Case Θ(1)
void BubbleSort(int A[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (A[j + 1] < A[j]) {
                swap(A[j], A[j + 1]);
            }
        }
    }
}