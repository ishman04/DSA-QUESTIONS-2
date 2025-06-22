#include<bits/stdc++.h>
using namespace std;
int main(){

}
class Solution {
  public:
    bool f(int n, int m, string &txt, string &pat, vector<vector<int>> &dp){
        if(n<0){
            if(m<0) return true;
            for(int i=0;i<=m;i++){
                if(pat[i]!='*'){
                    return false;
                }
            }
            return true;
        }
        if(m<0 && n>0) return false;
        
        if(dp[n][m]!=-1) return dp[n][m];
        
        if(pat[m]=='?'){
            return dp[n][m]=f(n-1,m-1,txt,pat,dp);
        }
        else if(pat[m]=='*'){
            return dp[n][m]=f(n-1,m-1,txt,pat,dp) || f(n-1,m,txt,pat,dp) || f(n,m-1,txt,pat,dp);
        }
        else if(pat[m]==txt[n]){
            return dp[n][m]=f(n-1,m-1,txt,pat,dp);
        }
        else return dp[n][m]=false;
    }
    bool wildCard(string &txt, string &pat) {
        // code here
        int n=txt.size(),m=pat.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(n-1,m-1,txt,pat,dp);
    }
};