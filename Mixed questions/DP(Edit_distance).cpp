#include<bits/stdc++.h>
using namespace std;
int main(){

}

class Solution {
public:
    vector<vector<int>> dp;
    int f(string word1, string word2,int i,int j){
        if(j==word2.length()) return word1.length()-i;
        if(i==word1.length()) return word2.length()-j;
        if(dp[i][j]!=-1) return dp[i][j];
        int res = 0;
        if(word1[i]==word2[j]){
            res = f(word1,word2,i+1,j+1);
        }
        else{
            int insertOp = 1+f(word1,word2,i,j+1);
            int deleteOp = 1+f(word1,word2,i+1,j);
            int replaceOp = 1+f(word1,word2,i+1,j+1);
            res = min({insertOp,deleteOp,replaceOp}); 
        }
        return dp[i][j] = res;
    }
    int minDistance(string word1, string word2) {
        dp.resize(word1.length()+2,vector<int>(word2.length()+2,-1));
        return f(word1,word2,0,0);
    }
};