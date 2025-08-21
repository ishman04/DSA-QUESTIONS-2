#include<bits/stdc++.h>
using namespace std;
int main(){

}


class Solution {
  public:
    vector<int> rank;
    vector<int> parent;
    int find(int a){
        if(parent[a]!=a){
            parent[a]=find(parent[a]);
        }
        return parent[a];
    }
    void unite(int a,int b){
        int para = find(a);
        int parb = find(b);
        if(para==parb) return;
        if(rank[para]>rank[parb]) parent[parb] = para;
        else if(rank[para]<rank[parb]) parent[para] = parb;
        else{
            parent[parb]=para;
            rank[para]++;
        }
    }
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        // code here
        int n = edges.size();
        rank.resize(V,0);
        parent.resize(V);
        for(int i=0;i<V;i++){
            parent[i] = i;
        }
        for(int i=0;i<edges.size();i++){
            unite(edges[i][0],edges[i][1]);
        }
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < V; i++){
            int root = find(i); 
            mp[root].push_back(i);
        }
        vector<vector<int>> ans;
        for(auto &kv : mp){
            ans.push_back(kv.second);
        }
        return ans;
    }
};
