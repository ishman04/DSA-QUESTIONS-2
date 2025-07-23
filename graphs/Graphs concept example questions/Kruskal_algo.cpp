//min cost to connect all points
#include <bits/stdc++.h>
using namespace std;
class DSU {
    vector<int> parent, rank;
public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int x) {
        if (x != parent[x])
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return false;
        if (rank[px] < rank[py]) parent[px] = py;
        else if (rank[px] > rank[py]) parent[py] = px;
        else {
            parent[py] = px;
            rank[px]++;
        }
        return true;
    }
};
class Solution{
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<tuple<int, int, int>> edges;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.emplace_back(dist, i, j);
            }
        }

        sort(edges.begin(), edges.end());

        DSU dsu(n);
        int mst_cost = 0, edges_used = 0;

        for (auto& [cost, u, v] : edges) {
            if (dsu.unite(u, v)) {
                mst_cost += cost;
                edges_used++;
                if (edges_used == n - 1) break;
            }
        }

        return mst_cost;
    }
};
