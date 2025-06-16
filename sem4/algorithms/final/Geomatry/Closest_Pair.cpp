#include <cmath>
#include <vector>
#include <limits>
using namespace std;

// Finds the distance between the closest pair of points by brute force
// Time Complexity: Θ(n²)
// Space Complexity: Θ(1)

struct Point {
    double x, y;
};

double Closest_Pair(const vector<Point>& P) {
    int n = P.size();
    double d = numeric_limits<double>::infinity();
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            double dx = P[i].x - P[j].x;
            double dy = P[i].y - P[j].y;
            double current_d = sqrt(dx*dx + dy*dy);
            if (current_d < d) {
                d = current_d;
            }
        }
    }
    return d;
}