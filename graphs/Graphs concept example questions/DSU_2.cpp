//connected components in undirected graph

#include<bits/stdc++.h>
using namespace std;
int main(){

}
class Solution {
public:
    int find(vector<int>& parent, int x) {
        if (parent[x] != x) {
            parent[x] = find(parent, parent[x]); // path compression
        }
        return parent[x];
    }

    void unionSet(vector<int>& parent, int a, int b, int& components) {
        int rootA = find(parent, a);
        int rootB = find(parent, b);
        if (rootA != rootB) {
            parent[rootA] = rootB;
            components--;
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parent(n);
        for (int i = 0; i < n; ++i) parent[i] = i;

        int components = n;

        for (auto& edge : edges) {
            unionSet(parent, edge[0], edge[1], components);
        }

        return components;
    }
};
