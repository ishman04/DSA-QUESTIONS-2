#include<bits/stdc++.h>
using namespace std;
int main(){

}
class Solution {
public:
    vector<vector<int>> v;
    void sum(int target, vector<int>& candidates,int i,vector<int> temp){
        if(target == 0){
            v.push_back(temp);
            return;
        }
        if(i==candidates.size()) return;
        if(candidates[i]<=target){
            temp.push_back(candidates[i]);
            sum(target-candidates[i],candidates,i+1,temp);
            temp.pop_back();
        }
        int j = i+1;
        while(j<candidates.size() && candidates[j]==candidates[j-1]){
            j++;
        }
        sum(target,candidates,j,temp);
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> temp;
        temp.clear();
        sum(target,candidates,0,temp);
        return v;
    }
};