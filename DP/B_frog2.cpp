#include<iostream>
#include<vector>
#include<climits>
#include<sstream>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;
vector<int> dp(100005,-1);
int n,k;
vector<int> h;
int f(int i){
    if(i>=h.size()) return INT_MAX;
    if(i==h.size()-1) return 0;
    if(dp[i]!=-1) return dp[i];
    int ans=INT_MAX;
    for(int j=1;j<=k;j++){
        if(i+j >= h.size()) break;
        ans=min(ans,abs(h[j+i]-h[i])+f(i+j));
    }
    return dp[i]=ans;
}
int main(){
cin>>n>>k;
h.resize(n);
for(int i=0;i<n;i++) cin>>h[i];
cout<<f(0);
}