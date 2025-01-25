//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here.
        unordered_map<int,int> mp;
        vector<int> result;
        unordered_set<int> st;
        for(int i=0;i<k;i++){
            st.insert(arr[i]);
            mp[arr[i]]++;
        }
        result.push_back(st.size());
        for(int i=k;i<arr.size();i++){
            mp[arr[i]]++;
            mp[arr[i-k]]--;
            if(arr[i]==arr[i-k]) result.push_back(result[result.size()-1]);
            else if(mp[arr[i-k]]==0 && mp[arr[i]]>1) result.push_back(result[result.size()-1]-1);
            else if(mp[arr[i-k]]==0 && mp[arr[i]]==1) result.push_back(result[result.size()-1]);
            else if(mp[arr[i-k]]!=0 && mp[arr[i]]>1) result.push_back(result[result.size()-1]);
            else if(mp[arr[i-k]]!=0 && mp[arr[i]]==1) result.push_back(result[result.size()-1]+1);
            
        }
        return result;
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
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution obj;
        vector<int> res = obj.countDistinct(arr, k);
        for (auto it : res)
            cout << it << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends