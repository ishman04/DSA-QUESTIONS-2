//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

const int MOD = 1e9+7;
class Solution {
  public:
    int sumoflength(vector<int>& arr) {
        // code
        unordered_set<int> st;
        int left = 0;
        int ans=0;
        int n = arr.size();
        for(int right=0;right<n;right++){
            while(st.find(arr[right])!=st.end()){
                st.erase(arr[left]);
                left++;
            }
            st.insert(arr[right]);
            ans = (ans + ((right - left + 1) * (right - left + 2)) / 2) % MOD;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.sumoflength(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends