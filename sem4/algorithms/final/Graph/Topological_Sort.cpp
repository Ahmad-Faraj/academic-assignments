#include <vector>
#include <queue>
using namespace std;

// Performs topological sort using Kahn's algorithm
// Time Complexity: O(V² + E)
// Space Complexity: O(V + E)
vector<int> Topological_Sort(vector<vector<int>>& graph, int V) {
    vector<int> inDegree(V, 0);
    vector<int> result;
    
    // Calculate in-degree for each vertex - O(E)
    for (int u = 0; u < V; u++) {
        for (int v : graph[u]) {
            inDegree[v]++;
        }
    }
    
    // Find vertices with in-degree 0 - O(V²)
    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }
    
    // Process vertices - O(V² + E)
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        result.push_back(u);
        
        for (int v : graph[u]) {
            if (--inDegree[v] == 0) {
                q.push(v);
            }
        }
    }
    
    return result;
}