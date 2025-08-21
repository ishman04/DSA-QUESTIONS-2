#include<bits/stdc++.h>
using namespace std;
int main(){

}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;
        deque<vector<int>> dq;
        for(int i=0;i<arr.size();i++){
            dq.push_back(arr[i]);
        }
        int j=0;
        while(j<arr.size() && dq.size()>1){
            auto first = dq.front();
            dq.pop_front();
            auto second = dq.front();
            dq.pop_front();
            vector<int> v(2);
            if(first[1]>=second[0]){
                v[0] = first[0];
                v[1] = max(first[1],second[1]);
                dq.push_front(v);
            }
            else{
                ans.push_back(first);
                dq.push_front(second);
            }
            j++;
        }
        for(auto ele: dq){
            ans.push_back(ele);
        }
        return ans;
    }
};