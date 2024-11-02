//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    bool dfs(int V, vector<int> adj[], int col[], int curr, int color) {
        col[curr] = color;
        
        for(int neigh : adj[curr]) {
            if(col[neigh] == -1) {
                if(!dfs(V, adj, col, neigh, !color))
                    return false;
            }
            else if(col[neigh] == color)
                return false;
        }
        return true;
    }
    
    bool isBipartite(int V, vector<int>adj[]) {
        int col[V];
        memset(col, -1, sizeof(col));
        
        for(int i = 0; i < V; i++) {
            if(col[i] == -1) {
                if(!dfs(V, adj, col, i, 0))
                    return false;
            }
        }
        return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends