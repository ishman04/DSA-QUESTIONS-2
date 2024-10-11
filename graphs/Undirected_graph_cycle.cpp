//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    vector<bool> visited;
    bool dfs(int V, vector<int> adj[],int node,int parent){
        for(auto i : adj[node]){
            if(!visited[i]){
                visited[i]= true;
                if(dfs(V,adj,i,node)){
                    return true;
                }
            }
            else{
                if(parent!=i) return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        for(int i=0;i<V;i++){
            visited.resize(V,false);
            if(visited[i]) continue;
            else{
                visited[i]=true;
                if(dfs(V,adj,i,-1)){
                    return true;
                }
            }
            
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends