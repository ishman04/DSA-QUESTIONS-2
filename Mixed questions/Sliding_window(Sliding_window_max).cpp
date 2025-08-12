#include<bits/stdc++.h>
using namespace std;
int main(){

}
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> ms;
        priority_queue<int> pq;
        for(int i=0;i<k;i++){
            pq.push(nums[i]);
        }
        int j = k;
        vector<int> ans;
        ans.push_back(pq.top());
        while(j<nums.size()){
            ms.insert(nums[j-k]);
            pq.push(nums[j]);
            while(ms.find(pq.top())!=ms.end()){
                auto it = ms.find(pq.top());
                ms.erase(it);
                pq.pop();
                
            }
            ans.push_back(pq.top());
            j++;
        }
        return ans;
    }
};