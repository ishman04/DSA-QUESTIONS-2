//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> dp;
    int f(vector<int>& height,int i){
        if(i>=height.size()) return INT_MAX;
        if(i == height.size()-1) return 0; 
        if(i==height.size()-2) return abs(height[i]-height[i+1]);
        if(dp[i]!=-1) return dp[i];
        int step1 = abs(height[i]-height[i+1]) + f(height,i+1);
        int step2 = abs(height[i]-height[i+2]) + f(height,i+2);
        return dp[i] = min(step1,step2);
    }
    int minCost(vector<int>& height) {
        // Code here
        dp.resize(100005,-1);
        return f(height,0);
    }
};

//{ Driver Code Starts.

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends