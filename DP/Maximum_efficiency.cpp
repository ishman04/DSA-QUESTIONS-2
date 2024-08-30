#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr.begin(),arr.end());
    int maxEff = INT_MIN;
    vector<int> result1(n);
    for(int i=0;i<n;i++){
        result1[i]=i-arr[i];
    }
    sort(result1.begin(),result1.end());
    cout<<result1[n-1]-result1[0]+1;
}