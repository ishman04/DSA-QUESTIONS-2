#include<bits/stdc++.h>
using namespace std;
int main(){

}
class Solution {
public:
    vector<vector<int>> tree;
    vector<int> result;
    vector<int> dfs(int node, int parent, string& labels){
        vector<int> count(26,0);
        count[labels[node]-'a'] = 1;
        for(auto child : tree[node]){
            if(child == parent) continue;
            vector<int> childCount = dfs(child,node,labels);
            for(int i=0;i<26;i++){
                count[i] += childCount[i];
            }
        }
        result[node] = count[labels[node] - 'a'];
        return count;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges,
                              string labels) {
        result.resize(n);
        tree.resize(n);
        for (auto& edge : edges) {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }
        dfs(0, -1,labels);
        return result;
    }
};