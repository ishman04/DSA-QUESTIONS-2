//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<vector<int>> dp;
    bool f(int n, int i, vector<int>& arr, int sum){
        if(sum == 0) return true;
        if(i==n) return false;
        if(dp[i][sum]!=-1) return dp[i][sum];
        bool nottake = f(n,i+1,arr,sum);
        if(sum < arr[i]){
            return dp[i][sum] = nottake;
        }
        bool take = f(n,i+1,arr,sum-arr[i]);
        return dp[i][sum] = nottake or take;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        dp.resize(arr.size()+2,vector<int>(sum+2,-1));
        return f(arr.size(),0,arr,sum);
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
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends