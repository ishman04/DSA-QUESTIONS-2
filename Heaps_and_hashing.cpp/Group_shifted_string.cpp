//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string getPattern(string &arr){
        string pattern = "";
        for(int i=1;i<arr.size();i++){
            int ch = ((arr[i-1]-arr[i]) + 26) % 26;
            pattern += (char) ch;
        }
        return pattern;
    }
    vector<vector<string>> groupShiftedString(vector<string> &arr) {
        // Your code here
        unordered_map<string,vector<string>> mp;
        for(auto word : arr){
            string str = getPattern(word);
            mp[str].push_back(word);
        }
        vector<vector<string>> ans;
        for(auto k : mp){
            ans.push_back(k.second);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        vector<vector<string>> v = ob.groupShiftedString(a);
        int n = v.size();
        for (int i = 0; i < n; i++) {
            sort(v[i].begin(), v[i].end());
        }
        sort(v.begin(), v.end());
        for (auto x : v) {
            for (auto y : x)
                cout << y << " ";
            cout << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends