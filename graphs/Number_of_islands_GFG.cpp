//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    int n,m;
    vector<vector<bool>> visited;
    void dfs(vector<vector<char>>& grid,int i,int j){
        if(i>=n || i<0 || j>=m || j<0 || grid[i][j]=='0') {
            return;
        }
        visited[i][j]=true;
        dfs(grid,i+1,j);
        dfs(grid,i-1,j);
        dfs(grid,i,j+1);
        dfs(grid,i,j-1);
        dfs(grid,i+1,j+1);
        dfs(grid,i+1,j-1);
        dfs(grid,i-1,j-1);
        dfs(grid,i-1,j+1);
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        n=grid.size();
        m=grid[0].size();
        int ans=0;
        visited.resize(n,vector<bool> (m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==false && grid[i][j]=='1'){
                    ans++;
                    dfs(grid,i,j);
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends