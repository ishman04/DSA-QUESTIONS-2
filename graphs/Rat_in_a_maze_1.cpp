//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  vector<vector<bool>> visited;
  vector<char> d = {'D','U','R','L'};
    vector<pair<int,int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
    vector<string>ans;
    void dfs(int i,int j,vector<vector<int>> &mat,string str){
        if(i==mat.size()-1 && j== mat[0].size()-1){
            ans.push_back(str);
            return;
        }
        for(int k=0;k<4;k++){
            auto s = dir[k];
            int r = i+s.first;
            int c = j+s.second;
            if(r>=0 && c>=0 && r<mat.size() && c<mat[0].size() && mat[r][c]==1 && !visited[r][c]){
                visited[r][c]=true;
                dfs(r,c,mat,str+d[k]);
                visited[r][c]=false;
            }
        }
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        if(mat[0][0]==0) return ans;
        visited.resize(mat.size(),vector<bool>(mat[0].size(),false));
        visited[0][0]=true;
        dfs(0,0,mat,"");
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends