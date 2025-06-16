#include <vector>
#include <cmath>
using namespace std;

// Solves system of linear equations using Gaussian elimination
// Time Complexity: Θ(n³)
// Space Complexity: Θ(n²)
vector<double> gaussianElimination(vector<vector<double>>& A) {
    int n = A.size();

    // Stage 1: Forward elimination (triangularization)
    for (int i = 0; i < n; i++) {
        // Partial pivoting
        int maxRow = i;
        for (int k = i+1; k < n; k++) {
            if (abs(A[k][i]) > abs(A[maxRow][i])) {
                maxRow = k;
            }
        }
        swap(A[i], A[maxRow]);

        // Eliminate column i
        for (int k = i+1; k < n; k++) {
            double factor = A[k][i] / A[i][i];
            for (int j = i; j <= n; j++) {
                A[k][j] -= factor * A[i][j];
            }
        }
    }

    // Stage 2: Back substitution
    vector<double> x(n);
    for (int i = n-1; i >= 0; i--) {
        x[i] = A[i][n] / A[i][i];
        for (int k = i-1; k >= 0; k--) {
            A[k][n] -= A[k][i] * x[i];
        }
    }

    return x;
}