//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    vector<vector<int>> dp;
    int f(int i, int n, vector<int>& val, vector<int>& wt, int w){
        if(i==n || w==0) return 0;
        if(dp[i][w]!=-1) return dp[i][w];
        int nottake = f(i+1,n,val,wt,w);
        if(wt[i]>w) return dp[i][w] = nottake;
        int takeAndStay = val[i] + f(i,n,val,wt,w-wt[i]);
        int take = val[i] + f(i+1,n,val,wt,w-wt[i]);
        return dp[i][w] = max({nottake,take,takeAndStay});
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = wt.size();
        dp.resize(n+2,vector<int>(capacity+2,-1));
        return f(0,wt.size(),val,wt,capacity);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int W;
        cin >> W;
        cin.ignore();
        string str;
        getline(cin, str);
        stringstream ss(str);
        vector<int> val;
        int num;
        while (ss >> num) {
            val.push_back(num);
        }
        string str2;
        getline(cin, str2);
        stringstream ss2(str2);
        vector<int> wt;
        int num2;
        while (ss2 >> num2) {
            wt.push_back(num2);
        }
        Solution ob;
        cout << ob.knapSack(val, wt, W) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends