#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> dsu;
    vector<int> rank;
    static bool cmp(vector<int>& a,vector<int>& b){
        return a[0]<b[0];
    }
    void Union(int a,int b){
        int root1 = find(a);
        int root2 = find(b);
        if(root1!=root2){
            if(rank[root1]>rank[root2]) dsu[root2]=root1;
            else if(rank[root1]<rank[root2]) dsu[root1]=root2;
            else{
                dsu[root2]=root1;
                rank[root1]++;
            }
        }
    }
    int find(int x){
        if(dsu[x]!=x) dsu[x] = find(dsu[x]);
        return dsu[x];
    }
    int makeConnected(int n, vector<vector<int>>& connections){
        sort(connections.begin(),connections.end(),cmp);
        dsu.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++) dsu[i]=i;
        for(int i=0;i<connections.size();i++){
            int a = connections[i][0];
            int b = connections[i][1];
            Union(a,b);
        }
        unordered_set<int> st;
        for(int i=0;i<n;i++) st.insert(find(i));
        if(connections.size()<n-1) return -1;
        return st.size()-1;
    }
};