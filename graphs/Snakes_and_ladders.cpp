#include<bits/stdc++.h>
using namespace std;
#define pp pair<int, int>
class Solution {
public:
    int n;
    vector<int> dir = {1, 2, 3, 4, 5, 6};

    int multisourceBfs(vector<int>& grid) {
        queue<pp> q;
        unordered_set<int> visited;
        q.push({0, 0});
        visited.insert(0);
        
        while (!q.empty()) {
            auto node = q.front();
            int ele = node.first;
            int moves = node.second;
            q.pop();

            if (ele == n * n - 1) return moves;

            for (int k = 1; k <= 6; k++) {
                int new_pos = ele + k;
                if (new_pos >= n * n) break;
                
                if (grid[new_pos] != -1) {
                    new_pos = grid[new_pos];
                }

                if (visited.find(new_pos) == visited.end()) {
                    visited.insert(new_pos);
                    q.push({new_pos, moves + 1});
                }
            }
        }
        return -1;
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        n = board.size();
        int m = n * n;
        vector<int> grid(m, -1);
        int idx = 0;
        bool leftToRight = true;

        for (int i = n - 1; i >= 0; i--) {
            if (leftToRight) {
                for (int j = 0; j < n; j++) {
                    grid[idx++] = board[i][j] == -1 ? -1 : board[i][j] - 1;
                }
            } else {
                for (int j = n - 1; j >= 0; j--) {
                    grid[idx++] = board[i][j] == -1 ? -1 : board[i][j] - 1;
                }
            }
            leftToRight = !leftToRight;
        }

        return multisourceBfs(grid);
    }
};
