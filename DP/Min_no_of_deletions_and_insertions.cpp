//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {

  public:
    vector<vector<int>> dp;
    int f(int i,int j ,int n ,int m ,string &s1, string &s2){
        if(i>=n || j>=m) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]){
            return dp[i][j] = 1+f(i+1,j+1,n,m,s1,s2);
        } 
        else{
            return dp[i][j] = max(f(i+1,j,n,m,s1,s2),f(i,j+1,n,m,s1,s2));
        }
    }
    int minOperations(string &s1, string &s2) {
        int n = s1.size();
        int m = s2.size();
        dp.resize(n+2,vector<int>(m+2,-1));
        int lcs = f(0,0,n,m,s1,s2);
        int add = s2.size()-lcs;
        int rem = s1.size()-lcs;
        return add + rem;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;

        Solution ob;
        cout << ob.minOperations(s1, s2) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends