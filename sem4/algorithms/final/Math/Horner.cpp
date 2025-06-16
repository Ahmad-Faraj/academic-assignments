// Evaluates polynomial using Horner's method
// Time Complexity: Θ(n)
// Space Complexity: Θ(1)
double horner(double P[], int n, double x) {
    double result = P[n];
    for (int i = n-1; i >= 0; i--) {
        result = result * x + P[i];
    }
    return result;
}