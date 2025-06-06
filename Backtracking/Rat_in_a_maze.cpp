#include<bits/stdc++.h>
using namespace std;
int main(){

}
class Solution {
  public:
    vector<string> result;
    vector<char> ch;
    vector<vector<int>> mark;
    string str = "";
    void canGo(vector<vector<int>>& maze,int row,int col){
        if(row == maze.size()-1 && col == maze.size()-1){
            result.push_back(str);
            return;
        }
        if(row > 0 && mark[row-1][col]==0 && maze[row-1][col]==1){
            mark[row-1][col]=1;
            str += "U";
            canGo(maze,row-1,col);
            str.pop_back();
            mark[row-1][col]=0;
        }
        if(row < maze.size()-1 && mark[row+1][col]==0 && maze[row+1][col]==1){
            mark[row+1][col]=1;
            str += "D";
            canGo(maze,row+1,col);
            str.pop_back();
            mark[row+1][col]=0;
        } 
        if(col > 0 && mark[row][col-1]==0 && maze[row][col-1]==1){
            mark[row][col-1]=1;
            str += "L";
            canGo(maze,row,col-1);
            str.pop_back();
            mark[row][col-1]=0;
        } 
        if(col < maze.size()-1 && mark[row][col+1]==0 && maze[row][col+1]==1){
            mark[row][col+1]=1;
            str += "R";
            canGo(maze,row,col+1);
            str.pop_back();
            mark[row][col+1]=0;
        } 
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        int n = maze.size();
        mark.resize(n,vector<int>(n,0));
        mark[0][0]=1;
        canGo(maze,0,0);
        sort(result.begin(),result.end());
        return result;
    }
};