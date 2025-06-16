// Multiplies two n×n matrices
// Time Complexity: Best/Average/Worst Case Θ(n³)
// Space Complexity: Best/Average/Worst Case Θ(n²) (for result matrix)
void Matrix_Multiplication(double** A, double** B, double** C, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            C[i][j] = 0.0;
            for (int k = 0; k < n; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}