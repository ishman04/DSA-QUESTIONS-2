#include<bits/stdc++.h>
using namespace std;
int main(){

}
class Solution {
public:
    vector<int> curr;
    vector<vector<int>> res;
    void recursion(vector<int>& nums,int idx){
        if(idx==nums.size()){
            res.push_back(curr);
            return;
        }
        recursion(nums,idx+1);
        curr.push_back(nums[idx]);
        recursion(nums,idx+1);
        curr.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
         recursion(nums,0);
         return res;
    }
};