//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//Back-end complete function Template for C++
#define ll long long
class Solution {
  public:
    ll ans = 0;
    ll f(int n, int i, vector<int>& A, int target){
        if(i==n && target == 0) return 1;
        if(i==n) return 0;
        ll add = f(n,i+1,A,target-A[i]);
        ll sub = f(n,i+1,A,target+A[i]);
        return ans = add+sub;
    }
    long long findTargetSumWays(int n, vector<int>& A, int target) {
        // Your code here
        return f(n,0,A,target);
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin >> N;
        vector<int> arr(N);

        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout << ob.findTargetSumWays(N, arr, target);
        cout << "\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends