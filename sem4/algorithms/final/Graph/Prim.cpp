// Finds MST using Prim's algorithm
// Time Complexity: O(E log V) with priority queue
// Space Complexity: O(V + E)
#include <vector>
#include <queue>
#include <climits>
using namespace std;

vector<pair<int,int>> primMST(vector<vector<pair<int,int>>>& graph, int start) {
    int V = graph.size();
    vector<int> key(V, INT_MAX);
    vector<int> parent(V, -1);
    vector<bool> inMST(V, false);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    pq.push({0, start});
    key[start] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        inMST[u] = true;

        for (auto& [v, weight] : graph[u]) {
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }

    vector<pair<int,int>> edges;
    for (int i = 1; i < V; i++) {
        if (parent[i] != -1) {
            edges.emplace_back(parent[i], i);
        }
    }
    return edges;
}