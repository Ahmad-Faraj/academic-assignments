#include <algorithm>
#include <cmath>
using namespace std;

// Multiplies two integers using divide-and-conquer method
// Time Complexity: O(n^1.585) (better than O(n^2) school method)
// Space Complexity: O(log n) due to recursion depth
long long multiply(long long x, long long y) {
    // Base case for single-digit multiplication
    if (x < 10 || y < 10) return x * y;

    // Calculate size of numbers
    int n = max(log10(x) + 1, log10(y) + 1);
    int m = n / 2;

    // Split numbers into halves
    long long power = pow(10, m);
    long long x_L = x / power;
    long long x_R = x % power;
    long long y_L = y / power;
    long long y_R = y % power;

    // Recursive calls
    long long P1 = multiply(x_L, y_L);
    long long P2 = multiply(x_R, y_R);
    long long P3 = multiply(x_L + x_R, y_L + y_R);

    // Combine results
    return P1 * pow(10, 2*m) + (P3 - P1 - P2) * pow(10, m) + P2;
}