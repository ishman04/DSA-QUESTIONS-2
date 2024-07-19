#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;
vector<int> dp;
int f(int n){
    if(n==1) return 1;
    if(n==2) return 2;
    return f(n-1) + (n-1)*f(n-2);
}
int main(){
    int n;
    cin>>n;
    dp.resize(n+5,-1);
    cout<<f(n);
}