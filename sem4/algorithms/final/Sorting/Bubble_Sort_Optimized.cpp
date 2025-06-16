#include <iostream>
using namespace std;

// Sorts an array with early termination if already sorted
// Time Complexity: Best Case Θ(n), Average/Worst Case Θ(n²)
// Space Complexity: Best/Average/Worst Case Θ(1)
void BubbleSortOpt(int A[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - 1 - i; j++) {
            if (A[j + 1] < A[j]) {
                swap(A[j], A[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;  // Early termination if no swaps
    }
}