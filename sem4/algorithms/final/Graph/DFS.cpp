#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Searches a graph using depth-first strategy
// Time Complexity: Θ(V + E)
// Space Complexity: Θ(V)
vector<int> DFS(vector<vector<int>>& graph, int start) {
    vector<int> result;
    vector<bool> visited(graph.size(), false);
    stack<int> s;
    s.push(start);
    visited[start] = true;

    while (!s.empty()) {
        int node = s.top();
        s.pop();
        result.push_back(node);
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                s.push(neighbor);
            }
        }
    }
    return result;
}