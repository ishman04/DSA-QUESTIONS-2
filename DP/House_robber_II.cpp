//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<int>> dp;
    int f(vector<int>& arr,bool flag,int i){
        if(i>=arr.size()) return 0;
        if(i==arr.size()-1 && flag) return 0;
        if(dp[i][flag]!=-1) return dp[i][flag];
        int take = f(arr,flag,i+2) + arr[i];
        int notTake = f(arr,flag,i+1);
        return dp[i][flag]=max(take,notTake);
    }
    int maxValue(vector<int>& arr) {
        // your code here
        int n = arr.size();
        if (n == 0) return 0;
        if (n == 1) return arr[0];
        dp.resize(n+1,vector<int>(2,-1));
        int take0 = f(arr,true,2) + arr[0];
        int notTake0 = f(arr,false,1);
        return max(take0,notTake0);
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        int res;
        res = ob.maxValue(arr);
        cout << res << "\n"
             << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends