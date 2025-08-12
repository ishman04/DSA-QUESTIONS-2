#include<bits/stdc++.h>
using namespace std;
int main(){

}

// User function Template for C++

class Solution {
  public:
    vector<vector<int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        if(A[0][0] != 1) return -1;
        queue<tuple<int,int,int>> q;
        q.push({0,0,0});
        vector<vector<bool>> visited(N,vector<bool>(M,false));
        visited[0][0] =true;
        while(!q.empty()){
            auto [r,c,distance] = q.front();
            q.pop();
            if(r==X && c==Y) return distance;
            for(auto d: dir){
                int nr = r+d[0];
                int nc = c+d[1];
                if(nr>=0 && nr<N && nc>=0 && nc<M && !visited[nr][nc] && A[nr][nc]==1){
                    q.push({nr,nc,distance+1});
                    visited[nr][nc] = true;
                }
            }
        }
        return -1;
    }
};