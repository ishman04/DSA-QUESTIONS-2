#include<bits/stdc++.h>
using namespace std;
int main(){

}
class Solution {
public:
    vector<vector<int>> dp;
    int f(vector<int>& nums,int idx,int ans){
        if(idx>=nums.size()) return ans;
        if(dp[idx][ans]!=-1) return dp[idx][ans];
        int rob = f(nums,idx+2,ans+nums[idx]);
        int dontRob = f(nums,idx+1,ans);
        return dp[idx][ans] = max(rob,dontRob);
    }
    int rob(vector<int>& nums) {
        dp.resize(nums.size()+2,vector<int>(40002,-1));
        return f(nums,0,0);
    }
};