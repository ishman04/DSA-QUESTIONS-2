/*You are required to complete this function*/
#include<bits/stdc++.h>
using namespace std;
int main(){

}
class Solution {
  public:
    int maxLen(vector<int>& arr) {
        // code here
        int n = arr.size();
        unordered_map<int,int> mp;
        int mxLen = 0;
        int sum = 0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum == 0) mxLen = i+1;
            
            if(mp.find(sum) != mp.end()){
                mxLen = max(mxLen, i-mp[sum]);
            }else{
                mp[sum] = i;
            }
        }
        return mxLen;
    }
};