//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the maximum money the thief can get.
    vector<int> dp;
    int f(vector<int>& arr,int i){
        if(i>=arr.size()) return 0; 
        if(dp[i]!=-1) return dp[i];
        return dp[i] = max(f(arr,i+2)+arr[i],f(arr,i+1));
    }
    int findMaxSum(vector<int>& arr) {
        // Your code here
        dp.resize(100005,-1);
        return f(arr,0);
    }
};

//{ Driver Code Starts.

int main() {

    // taking total testcases
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

        Solution ob;
        // calling function findMaxSum()
        cout << ob.findMaxSum(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends