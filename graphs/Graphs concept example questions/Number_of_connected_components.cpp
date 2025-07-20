//Number of islands

#include<bits/stdc++.h>
using namespace std;
int main(){

}
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;

        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};
        int ans = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    // Found a new island
                    ans++;
                    queue<pair<int,int>> q;
                    q.push({i, j});
                    visited[i][j] = true;

                    while (!q.empty()) {
                        auto [row, col] = q.front(); q.pop();

                        for (auto& d : dir) {
                            int nrow = row + d[0];
                            int ncol = col + d[1];
                            if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                                !visited[nrow][ncol] && grid[nrow][ncol] == '1') {
                                q.push({nrow, ncol});
                                visited[nrow][ncol] = true;
                            }
                        }
                    }
                }
            }
        }

        return ans;
    }
};
