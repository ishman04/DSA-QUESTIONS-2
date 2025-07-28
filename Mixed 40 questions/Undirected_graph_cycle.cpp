#include<bits/stdc++.h>
using namespace std;
int main(){

}
class Solution {
  public:
    vector<int> parent;
    int find(int a){
        if(parent[a] != a) parent[a] = find(parent[a]);
        return parent[a];
    }
    
    bool Union(int a, int b){
        int para = find(a);
        int parb = find(b);
        
        if(para == parb) return false;
        
        parent[parb] = para;
        return true;
    }
    
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        parent.resize(V,-1);
        for(int i = 0;i<V;i++) parent[i] = i;
        for(auto edge: edges){
            int a = edge[0];
            int b = edge[1];
            if(!Union(a,b)){
                return true;
            }
        }
        return false;
    }
};