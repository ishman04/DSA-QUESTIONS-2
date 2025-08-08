#include<bits/stdc++.h>
using namespace std;
int main(){

}

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> v(n,0);
        for(auto i: trust){
            v[i[0]-1]++;
        }
        int ans =-1;
        for(int i=0;i<v.size();i++) {
            if(v[i]==0) ans = i;
        }
        int count=0;
        for(int i=0;i<trust.size();i++){
            if(trust[i][1]==ans+1) count++;
        }
        return count==n-1 ? ans+1 : -1; 
    }
};