#include<bits/stdc++.h>
using namespace std;
int main(){

}
class Solution {
public:
    unordered_set<int> v;int ans=0;
    void bfs(vector<list<int>> graph,int src){
        queue<int> q;
        q.push(src);
        
        v.insert(src);
        while(!q.empty()){
            auto ele = q.front();
            q.pop();
            for(auto neigh : graph[ele]){
                if(v.find(neigh)==v.end()){
                    v.insert(neigh);
                    q.push(neigh);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<list<int>> graph(n,list<int> ());
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(arr[i][j]==1) graph[i].push_back(j);
            }
        }
        for(int i=0;i<n;i++){
            if (v.find(i) == v.end()) {
                bfs(graph, i);
                ans++;
            }
        }
        return ans;
    }
};