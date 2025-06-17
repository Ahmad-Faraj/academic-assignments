#include <iostream>
#include <cmath>
using namespace std;

// Computes GCD using prime factorization up to sqrt(min(m,n))
// Time Complexity: O(sqrt(min(m,n)))
// Space Complexity: O(1)
int Factor_GCD(int m, int n) {
    int gcd = 1;
    int limit = sqrt(min(m, n));
    for (int i = 2; i <= limit; i++) {
        while (m % i == 0 && n % i == 0) {
            gcd *= i;
            m /= i;
            n /= i;
        }
    }
    if (m == n) gcd *= m;
    return gcd;
}
