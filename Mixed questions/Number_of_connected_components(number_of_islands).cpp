#include<bits/stdc++.h>
using namespace std;
int main(){

}
class Solution {
public:
    int n;int m;
    vector<vector<bool>> visited;
    void dfs(vector<vector<char>>& grid,int i,int j){
        if(i<0 || i>=n || j<0 || j>=m || visited[i][j] || grid[i][j]=='0') return;
        visited[i][j] = true;
        dfs(grid,i+1,j);
        dfs(grid,i-1,j);
        dfs(grid,i,j+1);
        dfs(grid,i,j-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        n = grid.size();
        m = grid[0].size();
        visited.resize(n,vector<bool>(m,false));

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    ans++;
                    dfs(grid,i,j);
                }
            }
        }
        return ans;
    }
};