#include<bits/stdc++.h>
using namespace std;
int main(){

}
class Solution {
public:
    static bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
    vector<int> topKFrequent(vector<int>& arr, int k) {
        sort(arr.begin(),arr.end());
        vector<pair<int,int>> v;
        int count=1;
        if(arr.size()==1) return arr;
        for(int i=1;i<arr.size();i++){
            if(arr[i-1]==arr[i]){
                count++;
                continue;
            }
            else {
                v.push_back({arr[i-1],count});
                count=1;
            }
        }
        v.push_back({arr[arr.size()-1],count});
        sort(v.begin(),v.end(),cmp);
        vector<int> ans;
        for(int i=0;i<v.size();i++){
            if(k>0){
                ans.push_back(v[i].first);
                k--;
            } 
        }
        return ans;
    }
};