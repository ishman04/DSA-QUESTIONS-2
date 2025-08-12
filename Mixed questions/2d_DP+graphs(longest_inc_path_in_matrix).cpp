#include<bits/stdc++.h>
using namespace std;
int main(){

}
class Solution {
public:
    int m,n; 
    vector<vector<int>> dp;
    vector<vector<int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    int dfs(vector<vector<int>>& matrix,int i,int j){
        if (dp[i][j] != -1) return dp[i][j];

        int maxPath = 1;
        for (auto& dir : directions) {
            int x = i + dir[0], y = j + dir[1];
            if (x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] > matrix[i][j]) {
                maxPath = max(maxPath, 1 + dfs(matrix, x, y));
            }
        }

        return dp[i][j] = maxPath;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        dp.resize(m+2,vector<int>(n+2,-1));
        int ans = INT_MIN;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                ans = max(ans,dfs(matrix,i,j));
            }
        }
        return ans;
    }
};