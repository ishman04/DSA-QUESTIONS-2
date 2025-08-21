#include<bits/stdc++.h>
using namespace std;
int main(){

}
class Solution {
public:
    vector<int> ans;
    set<vector<int>>v;

    void recursion(vector<int>& candidates, int target, int idx){
        if(target<0) return;
        if(target == 0){
            v.insert(ans);
            return;
        }
        if(idx == candidates.size()) return;

        recursion(candidates,target,idx+1);
        ans.push_back(candidates[idx]);
        recursion(candidates,target-candidates[idx],idx);
        recursion(candidates,target-candidates[idx],idx+1);
        ans.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        recursion(candidates,target,0);
        vector<vector<int>> sol;
        for(auto i: v){
            sol.push_back(i);
        }
        return sol;
    }
};