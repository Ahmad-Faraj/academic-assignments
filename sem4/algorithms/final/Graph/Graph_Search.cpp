#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Checks if target exists in graph from start node
// Time Complexity: Θ(V + E)
// Space Complexity: Θ(V)
bool Graph_Search(vector<vector<int>>& graph, int start, int target) {
    vector<bool> visited(graph.size(), false);
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        if (node == target) return true;
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    return false;
}