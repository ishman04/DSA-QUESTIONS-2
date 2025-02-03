//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// long long int maxSum(int arr[], int n);

// } Driver Code Ends

#define ll long long
class Solution {
  public:
    long long maxSum(vector<int>& arr) {
        // code here
        sort(arr.begin(),arr.end());
        vector<int> arr1;
        int n = arr.size();
        int i = 0;
        int j = n-1;
        while(i<=j){
            if(i==j){
                arr1.push_back(arr[i]);
                break;
            }
            arr1.push_back(arr[i]);
            arr1.push_back(arr[j]);
            i++;
            j--;
        }
        ll ans = 0;
        for(int i = 1; i<n;i++){
            ans += abs(arr1[i]-arr1[i-1]);
        }
        ans += abs(arr1[0] - arr1[n-1]);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num) {
            arr.push_back(num);
        }

        Solution ob;
        long long ans = ob.maxSum(arr);

        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends