//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<pair<int,int>> result;
    int j=0;
    void inorder(vector<int>& arr, int idx){
        if(idx>=arr.size()) return;
        inorder(arr,2*idx+1);
        result.push_back({arr[idx],j});
        j++;
        inorder(arr,2*idx+2);
    }
    int minSwaps(vector<int>& arr) {
        // Write your code here
        
        inorder(arr,0);
        int ans = 0;
        
        sort(result.begin(),result.end());
        for(int i=0;i<result.size();i++){
            if(result[i].second==i) continue;
            int idx = result[i].second;
            swap(result[idx],result[i]);
            if(i!=result[idx].second){
                i--;
            }
            ans++;
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
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        cout << ob.minSwaps(arr) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends