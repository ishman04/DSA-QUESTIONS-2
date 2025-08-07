#include<bits/stdc++.h>
using namespace std;
int main(){

}
class Solution {
public:
    vector<vector<bool>> visited;
    int dfs(vector<vector<int>>& grid,int x,int y){
        if(x<0 || x>=grid[0].size() || y<0 || y>=grid.size() || visited[y][x] || grid[y][x]==0) return 0;
        
        visited[y][x] = true;
        int area = 1;
        area += dfs(grid,x+1,y);
        area += dfs(grid,x-1,y);
        area += dfs(grid,x,y+1);
        area += dfs(grid,x,y-1);

        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid[0].size();
        int m = grid.size();
        visited.resize(m,vector<bool>(n,false));
        int mx_area = 0; 
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && visited[i][j]==false){
                    mx_area = max(mx_area,dfs(grid,j,i));
                }
            }
        }
        return mx_area;
    }
};