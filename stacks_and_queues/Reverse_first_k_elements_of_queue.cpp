//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        // add code here.
        stack<int> st;
        queue<int> ans;
        while(k!=0){
            int ele = q.front();
            q.pop();
            st.push(ele);
            k--;
        }
        while(!st.empty()){
            int ele = st.top();
            st.pop();
            ans.push(ele);
        }
        while(!q.empty()){
            int ele = q.front();
            q.pop();
            ans.push(ele);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        Solution ob;
        queue<int> ans = ob.modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends