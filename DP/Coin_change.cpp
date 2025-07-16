//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<vector<int>> dp;
    int f(int i,int n, vector<int>& coins, int sum){
        if(sum==0) return 1;
        if(i==n || sum < 0 ) return 0;
        if(dp[i][sum]!=-1) return dp[i][sum];
        int nottake = f(i+1,n,coins,sum);
        int take = f(i,n,coins,sum-coins[i]);
        return dp[i][sum] = nottake + take;
    }
    int count(vector<int>& coins, int sum) {
        // code here. 
        int n = coins.size();
        dp.resize(n+1,vector<int> (sum+2,-1));
        return f(0,n,coins,sum);
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();
        Solution ob;
        cout << ob.count(arr, sum) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends