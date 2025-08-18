#include<bits/stdc++.h>
using namespace std;
int main(){

}

class Solution {
public:
    vector<int> dp;
    bool f(int st, string &s, unordered_set<string>& dict){
        if(st == s.size()) return true;
        if(dp[st] !=-1) return dp[st];
        for(int end = st+1;end<=s.size();end++){
            string word = s.substr(st,end-st);
            if(dict.count(word) && f(end,s,dict)){
                return dp[st] = 1;
            }
        }
        return dp[st] = 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(),wordDict.end());
        int n = s.size();
        dp.resize(n,-1);
        return f(0,s,dict);
    }
};