#include<bits/stdc++.h>
using namespace std;
int main(){

}
class Solution {
public:
    int rows, cols;
    vector<vector<bool>> visited;

    bool dfs(vector<vector<char>>& board, int i, int j, vector<pair<int,int>>& component) {
        if(i<0 || i>=rows || j<0 || j>=cols) return false; // touches boundary
        if(board[i][j] == 'X' || visited[i][j]) return true;

        visited[i][j] = true;
        component.push_back({i,j});

        bool up    = dfs(board, i-1, j, component);
        bool down  = dfs(board, i+1, j, component);
        bool left  = dfs(board, i, j-1, component);
        bool right = dfs(board, i, j+1, component);

        return up && down && left && right;
    }

    void solve(vector<vector<char>>& board) {
        rows = board.size();
        cols = board[0].size();
        visited.assign(rows, vector<bool>(cols, false));

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(board[i][j]=='O' && !visited[i][j]) {
                    vector<pair<int,int>> component;
                    bool surrounded = dfs(board, i, j, component);

                    if(surrounded) {
                        for(auto [x,y] : component) {
                            board[x][y] = 'X';
                        }
                    }
                }
            }
        }
    }
};
