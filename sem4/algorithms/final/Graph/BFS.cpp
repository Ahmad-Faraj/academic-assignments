#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Searches a graph using breadth-first strategy
// Time Complexity: Θ(V + E)
// Space Complexity: Θ(V)
vector<int> BFS(vector<vector<int>>& graph, int start) {
    vector<int> result;
    vector<bool> visited(graph.size(), false);
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node);
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    return result;
}