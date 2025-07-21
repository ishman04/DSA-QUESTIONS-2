//Graph valid tree

#include<bits/stdc++.h>
using namespace std;
int main(){

}
class Solution {
public:
    int find(vector<int>& parent,int a){
        if(parent[a]!=a) parent[a] = find(parent,parent[a]);
        return parent[a];
    }
    bool Union(int a,int b,vector<int>& parent){
        int pa = find(parent,a);
        int pb = find(parent,b);
        if(pa == pb) return false;
        parent[pa] = pb; 
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1) return false;

        vector<int> parent(n);
        for (int i = 0; i < n; ++i) parent[i] = i;

        for(int i=0;i<edges.size();i++){
            if(!Union(edges[i][0],edges[i][1],parent)) return false;
        }
        return true;
    }   
};
