//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<vector<int>> dp;
    int f(int n,int prev, int i, vector<int>& arr){
        if(i==n) return 0;
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        int take = INT_MIN;
        int nottake = INT_MIN;
        if(prev==-1 || arr[i]>arr[prev]){
            take = 1 + f(n,i,i+1,arr);
        }
        nottake = f(n,prev,i+1,arr);
        return dp[i][prev+1] = max(take,nottake);
    }
    int lis(vector<int>& arr) {
        // code here
        int n = arr.size();
        dp.resize(n+2,vector<int>(n+2,-1));
        return f(n,-1,0,arr);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input

    while (t--) {
        int n;
        vector<int> arr;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            arr.push_back(num);

        Solution obj;
        cout << obj.lis(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends