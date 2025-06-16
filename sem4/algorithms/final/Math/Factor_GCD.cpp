#include <iostream>
using namespace std;

// Computes GCD using prime factorization
// Time Complexity: O(sqrt(min(m,n)))
// Space Complexity: O(1)
int Factor_GCD(int m, int n) {
    int gcd = 1;
    for (int i = 2; i <= min(m, n); i++) {
        while (m % i == 0 && n % i == 0) {
            gcd *= i;
            m /= i;
            n /= i;
        }
    }
    return gcd;
}