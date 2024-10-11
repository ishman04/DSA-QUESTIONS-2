#include<bits/stdc++.h>
using namespace std;
vector<list<int>> graph;
void add_edge(int v,int u){
    graph[v].push_back(u);
}
bool isCycle(){
    int n = graph.size();
    vector<int> indegree(n,0);
    for(int i=0;i<n;i++){
        int x = graph[i].size();
        for (auto it : graph[i]) {
           indegree[it]++;
        }
    }
    queue<int> q;
    for(int i=0;i<n;i++){
        if(indegree[i]==0) {
            q.push(i);
            indegree[i]=INT_MAX;
        }
    }
    vector<int> ans;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        ans.push_back(x);
        for(auto i : graph[x]){
            indegree[i]--;
        }
        for(int i=0;i<n;i++){
            if(indegree[i]==0) {
                q.push(i);
                indegree[i]=INT_MAX;
        }
    }

}
if(ans.size()==n) return false;
else return true;
}
int main(){
    int v,e;
    cin>>v>>e;
    graph.resize(v);
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        add_edge(a,b);
    }
    cout<<isCycle();
}