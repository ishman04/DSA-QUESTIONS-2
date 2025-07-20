//Islands and treasure

#include<bits/stdc++.h>
using namespace std;
int main(){

}
class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return;

        int m = grid.size();
        int n = grid[0].size();
        const int INF = 2147483647;
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        queue<pair<int, int>> q;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }
        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            for (auto [dr, dc] : directions) {
                int r = row + dr;
                int c = col + dc;

                if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == INF) {
                    grid[r][c] = grid[row][col] + 1;
                    q.push({r, c});
                }
            }
    }
    }
};
