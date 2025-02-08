//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<int>> dp;
    int f(vector<vector<int>>& mat,int i,int j){
        if(i>=mat.size() || i<0 || j>=mat[0].size() || j<0) return INT_MIN;
        if(i==mat.size()-1) return mat[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int op1 = f(mat,i+1,j-1) + mat[i][j];
        int op2 = f(mat,i+1,j) + mat[i][j];
        int op3 = f(mat,i+1,j+1) + mat[i][j];
        return dp[i][j]=max({op1,op2,op3});
    }
    int maximumPath(vector<vector<int>>& mat) {
        // code here
        int res = INT_MIN;
        dp.resize(505,vector<int>(505,-1));
        for(int i=0;i<mat[0].size();i++){
            res=max(f(mat,0,i),res);
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        cout << ob.maximumPath(mat) << "\n";
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends