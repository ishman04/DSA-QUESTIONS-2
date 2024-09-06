//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<int> dp;
      int f(vector<int> &nums, int k, int idx) {
        if (idx == nums.size()) return 0;
        if (dp[idx] != -1) return dp[idx];
        
        int currLen = 0;
        int minCost = INT_MAX;

        for (int i = idx; i < nums.size(); i++) {
            currLen += nums[i];
            if (currLen > k) break;
            
            int extraSpace = k - currLen;
            int cost = (i == nums.size() - 1) ? 0 : extraSpace * extraSpace;
            
            minCost = min(minCost, cost + f(nums, k, i + 1));

            currLen++;  // Add space between words
        }
        
        return dp[idx] = minCost;
    }
    int solveWordWrap(vector<int>nums, int k) 
    { 
        // Code here
        dp.resize(nums.size()+1,-1);
        return f(nums,k,0);
    } 
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}
// } Driver Code Ends