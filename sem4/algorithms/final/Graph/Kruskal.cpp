// Finds MST using Kruskal's algorithm
// Time Complexity: O(E log E)
// Space Complexity: O(V + E)
#include <vector>
#include <algorithm>
using namespace std;

struct DSU {
    vector<int> parent, rank;
    DSU(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }
    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y);
        parent[y] = x;
        if (rank[x] == rank[y]) rank[x]++;
        return true;
    }
};

vector<pair<int,int>> kruskalMST(vector<vector<pair<int,int>>>& graph) {
    vector<tuple<int,int,int>> edges;
    for (int u = 0; u < graph.size(); u++) {
        for (auto& [v, w] : graph[u]) {
            if (u < v) edges.emplace_back(w, u, v);
        }
    }
    sort(edges.begin(), edges.end());

    DSU dsu(graph.size());
    vector<pair<int,int>> mst;
    for (auto& [w, u, v] : edges) {
        if (dsu.unite(u, v)) {
            mst.emplace_back(u, v);
            if (mst.size() == graph.size() - 1) break;
        }
    }
    return mst;
}