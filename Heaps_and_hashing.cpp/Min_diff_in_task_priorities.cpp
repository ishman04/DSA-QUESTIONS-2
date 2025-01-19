//{ Driver Code Starts
#include <bits/stdc++.h>
#include <math.h>
#include <stdio.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minDiff(vector<int>& arr, int k, int m, int t) {
        // write code here
        sort(arr.begin(),arr.end());
        int n = arr.size();
        vector<int> ans;
        int x=k;
        for(int i = n-1;i>=0;i--){
            if(k>0){
                ans.push_back(arr[i]);
                k--;
            }
            else break;
        }
        for(int i=0;i<ans.size();i++){
            if(ans[i]>=t) m--;
            if(m==0) break;
        }
        if(m<=0) return ans[0]-ans[x-1];
        return -1;
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
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        string ms;
        getline(cin, ms);
        int m = stoi(ms);
        string ts;
        getline(cin, ts);
        int th = stoi(ts);
        Solution obj;
        cout << obj.minDiff(arr, k, m, th) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends