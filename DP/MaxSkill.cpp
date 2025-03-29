//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int f(int i,int j,vector<int> &arr){
        if(i>j) return 0;
        int ans = INT_MIN;
        for(int k=i;k<=j;k++){
            int sum = f(i,k-1,arr) + f(k+1,j,arr) + arr[i-1]*arr[j+1]*arr[k];
            ans = max(ans,sum);
        }
        return ans;
    }
    int maxSkill(vector<int> &arr) {
        // code here
        int n = arr.size();
        arr.insert(arr.begin(),1);
        arr.push_back(1);
        return f(1,n,arr);
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution obj;
        cout << obj.maxSkill(arr) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends