//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#define ll long long
class Solution {
  public:
    vector<vector<int>> mat;
    vector<vector<vector<ll>>> dp;
    ll f(int i,int j,int n,int count){
        if(i>=mat.size() || j>=mat[0].size() || i<0 || j<0 || count>n) return 0;
        if(i==3 && (j==0 || j==2)) return 0;
        if(count==n) return 1;
        if(dp[i][j][count]!=-1) return dp[i][j][count];
        ll ans =0;
        ans = f(i,j,n,count+1)+f(i,j+1,n,count+1) + f(i+1,j,n,count+1) + f(i-1,j,n,count+1)+ f(i,j-1,n,count+1);
        return dp[i][j][count]=ans;
        
    }
    long long getCount(int n) {
        // Your code goes here
        ll mx=0;
        mat.resize(4,vector<int> (3,0));
        dp.resize(4, vector<vector<ll>>(3, vector<ll>(n + 1, -1)));
        for(int i=0;i<4;i++){
            for(int j=0;j<3;j++){
                if(i==3 && j==0) continue;
                if(i==3 && j==2) continue;
                mx+=f(i,j,n,1);
            }
        }
        return mx;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        cout << ob.getCount(n) << "\n";
    }
    return 0;
}

// } Driver Code Ends