//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
    vector<int> finish;
    void dfs(int V, vector<vector<int>>& adj,int i,stack<int>& st,vector<bool>& visited){
        visited[i]=true;
        for(int neigh : adj[i]){
            if(!visited[neigh]){
                dfs(V,adj,neigh,st,visited);
            }
        }
        st.push(i);
    }
    void reverseDfs(int i,vector<vector<int>>& gr,vector<bool>& visited){
            visited[i]=true;
            for (int neighbor :gr[i]) {
            if (!visited[neighbor]) {
                reverseDfs(neighbor, gr, visited);
            }
        }
    }
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        vector<bool> vis(V,false);
        stack<int> st;
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(V, adj, i, st, vis);
            }
        }
        vector<vector<int>> transpose(V);
        for(int i=0;i<V;i++){
            for(auto neigh : adj[i]){
                transpose[neigh].push_back(i);
            }
        }
        fill(vis.begin(), vis.end(), false);
        int sccCount = 0;
        
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            
            // If node is not visited, it means we've found a new SCC
            if (!vis[node]) {
                reverseDfs(node, transpose, vis);
                sccCount++; // Count each call as one SCC
            }
        }
        
        return sccCount;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    
cout << "~" << "\n";
}

    return 0;
}


// } Driver Code Ends