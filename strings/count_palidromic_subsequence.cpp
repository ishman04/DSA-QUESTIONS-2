#include<bits/stdc++.h>
using namespace std;
int main(){

}
class Solution {
  public:
    /*You are required to complete below method */
     const int MOD = 1e9 + 7;
    vector<vector<int>> dp;

    int helper(string& s, int i, int j) {
        if (i > j) return 0;
        if (i == j) return 1;

        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == s[j]) {
            dp[i][j] = (1 + helper(s, i + 1, j) + helper(s, i, j - 1)) % MOD;
        } else {
            dp[i][j] = ((helper(s, i + 1, j) + helper(s, i, j - 1)) % MOD - helper(s, i + 1, j - 1) + MOD) % MOD;
        }

        return dp[i][j];
    }

    int countPS(string s) {
        int n = s.size();
        dp.assign(n, vector<int>(n, -1));
        return helper(s, 0, n - 1);
        
    }
};