#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;
string ans="";
int f(string &str1, string &str2, int i,int j,string out){ 
    if(ans.size()<out.size()) ans=out;  
    if(i<0 || j<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    return dp[i][j] = max({( (str1[i]==str2[j]) ? 1+f(str1,str2,i-1,j-1,out+str1[i]) : INT_MIN ),f(str1,str2,i-1,j,out),f(str1,str2,i,j-1,out)});
}
int main(){
    string s1,s2;
    cin>>s1>>s2;
    dp.resize(1005,vector<int> (1005,-1));
    f(s1,s2,s1.length()-1,s2.length()-1,"");
    reverse(ans.begin(),ans.end());
    cout<<ans;
}