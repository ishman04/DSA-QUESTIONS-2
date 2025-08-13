#include<bits/stdc++.h>
using namespace std;
int main(){

}

class Solution {
public:
    map<int,string> mp;
    vector<string> result;
    string ans;
    void dfs(string digits, int idx,int n){
        if(idx==n) {
            result.push_back(ans);
            return;
        }
        int n1 = digits[idx]-'0';
        for(int i=0;i<mp[n1].size();i++){
            ans += mp[n1][i];
            dfs(digits,idx+1,n);
            ans.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits == "") return result;
        int n = digits.length();
        mp[2] = "abc";mp[3]="def";mp[4]="ghi";mp[5]="jkl";mp[6]="mno";mp[7]="pqrs";mp[8]="tuv";mp[9]="wxyz";
        dfs(digits,0,n);
        return result;
    }
};