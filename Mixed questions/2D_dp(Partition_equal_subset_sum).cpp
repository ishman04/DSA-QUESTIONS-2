#include<bits/stdc++.h>
using namespace std;
int main(){

}
class Solution {
public:
    vector<vector<int>> dp;
    bool f(vector<int>& nums,int i,int target){
        if(target == 0) return true;
        if(i==nums.size() || target<0) return false;
        if(dp[i][target]!=-1) return dp[i][target];
        bool take = f(nums,i+1,target-nums[i]);
        bool nottake = f(nums,i+1,target);

        return dp[i][target] = take || nottake;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
        }
        if(sum%2!=0) return false;
        int target = sum/2;
        dp.resize(202,vector<int>(target+2,-1));
        return f(nums,0,target);
    }
};