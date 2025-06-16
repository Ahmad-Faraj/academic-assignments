// Performs multiplication using Russian Peasant method
// Time Complexity: Θ(log n) where n is the smaller number
// Space Complexity: Θ(1)
int Russian_Multiply(int a, int b) {
    int x = a, y = b;
    int z = 0;
    while (x > 0) {
        if (x % 2 == 1) {
            z += y;
        }
        y <<= 1;
        x >>= 1;
    }
    return z;
}