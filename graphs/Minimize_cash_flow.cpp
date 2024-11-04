//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int getMin(vector<int> &a){
        int mini=INT_MAX;
        int idx = -1;
        for(int i=0;i<a.size();i++){
            if(a[i]<mini) {
                mini=a[i];
                idx=i;
            }
                
        }
        return idx;
    }
    int getMax(vector<int> &a){
        int maxi=INT_MIN;
        int idx = -1;
        for(int i=0;i<a.size();i++){
            if(a[i]>maxi) {
                maxi=a[i];
                idx=i;
            }
        }
        return idx;
    }
    void minimize(vector<int>& netAmount, vector<vector<int>>& result) {
        int minIdx = getMin(netAmount);
        int maxIdx = getMax(netAmount);
    
        if (netAmount[minIdx] >= 0 || netAmount[maxIdx] <= 0) {
            return;
        }
        int minAmount = min(-netAmount[minIdx], netAmount[maxIdx]);
        
        result[minIdx][maxIdx] = minAmount;
        
        netAmount[minIdx] += minAmount;
        netAmount[maxIdx] -= minAmount;
        
        minimize(netAmount, result);
    }
    
    vector<vector<int>> minCashFlow(vector<vector<int>>& transaction, int n) {
        vector<int> netAmount(n, 0);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                netAmount[i] += (transaction[j][i] - transaction[i][j]);
            }
        }
        vector<vector<int>> result(n, vector<int>(n, 0));
        minimize(netAmount, result);
        
        return result;
    }
};


//{ Driver Code Starts.

vector<int> balance(vector<vector<int>>& v, int n) {
    vector<int> bal(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            bal[i] -= v[i][j];
            bal[j] += v[i][j];
        }
    }
    return bal;
}

bool isValid(vector<vector<int>>& g, vector<vector<int>>& r, int n) {
    return balance(g, n) == balance(r, n);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> g(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cin >> g[i][j];
        }
        Solution obj;
        vector<vector<int>> r = obj.minCashFlow(g, n);
        if (isValid(g, r, n) == false) {
            cout << "-1\n";
            continue;
        }
        int flow = 0;
        for (auto j : r) {
            for (auto i : j) {
                if (i > 0)
                    flow++;
            }
        }
        cout << flow << "\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends