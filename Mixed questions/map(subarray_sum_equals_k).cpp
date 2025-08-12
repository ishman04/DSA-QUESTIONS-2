#include<bits/stdc++.h>
using namespace std;
int main(){

}
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> prefixSumFreq;
        prefixSumFreq[0]=1;
        int count = 0;
        int curr = 0;
        for(int num: nums){
            curr += num;
            if(prefixSumFreq.find(curr-k) != prefixSumFreq.end()){
                count += prefixSumFreq[curr-k];
                }
            prefixSumFreq[curr]++;
        }
        return count;
    }
};