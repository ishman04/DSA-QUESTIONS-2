//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return the minimum cost of connecting the ropes.
    int minCost(vector<int>& arr) {
        // code here
        priority_queue<int,vector<int>,greater<int>> pq;
        int cost = 0;
        for(int i=0;i<arr.size();i++){
            pq.push(arr[i]);
        }
        while(pq.size() > 1){
            if(pq.size()==1) return pq.top();
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            int z = x+y;
            pq.push(z);
            cost+=z;
        }
        return cost;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> a;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(a) << endl;
        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends