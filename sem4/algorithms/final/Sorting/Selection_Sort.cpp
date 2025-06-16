#include <iostream>
using namespace std;

// Sorts an array in ascending order by repeatedly selecting the minimum element  
// Time Complexity: Best/Average/Worst Case Θ(n²)  
// Space Complexity: Best/Average/Worst Case Θ(1)  
void SelectionSort(int A[], int n) {  
    for (int i = 0; i <= n - 2; i++) {  
        int min = i;  
        for (int j = i + 1; j <= n - 1; j++) {  
            if (A[j] < A[min]) {  
                min = j;  
            }  
        }  
        swap(A[i], A[min]);  
    }  
}  