#include<bits/stdc++.h>
using namespace std;
int main(){

}

class Solution {
public:
    vector<vector<int>> dp;
    int f(vector<int>& nums,int idx,int parent){
        if(idx==nums.size()){
            return 0;
        }
        if(dp[idx][parent+1]!=-1) return dp[idx][parent+1];
        int notTake = f(nums,idx+1,parent);
        int take = 0;
        if (parent == -1 || nums[idx] > nums[parent]) {
            take = 1 + f(nums, idx + 1, idx);
        }
        return dp[idx][parent+1] = max(take,notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        dp.resize(nums.size()+1,vector<int>(nums.size()+1,-1));
        return f(nums,0,-1);
    }
};