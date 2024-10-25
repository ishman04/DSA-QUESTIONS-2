//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<int> dist;
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // Code here
	    dist.resize(n,INT_MAX);
	    dist[1]=0;
	    for(int i=0;i<n;i++){
	        for(int j=0;j<edges.size();j++){
	            int u=edges[j][0];
	            int v=edges[j][1];
	            int w=edges[j][2];
	            if(dist[u]!=INT_MAX && dist[v]>dist[u]+w){
	                dist[v]=dist[u]+w;
	            }
	        }
	    }
	    for(int j = 0; j < edges.size(); j++) {
	        int u = edges[j][0];
	        int v = edges[j][1];
	        int w = edges[j][2];
	        if(dist[u] != INT_MAX && dist[v] > dist[u] + w) {
	            return 1; // Negative weight cycle exists
	        }
	    }
	    
	    return 0;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends