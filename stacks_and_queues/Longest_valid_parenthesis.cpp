//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxLength(string& s) {
       stack<int> st;
        st.push(-1); // Base index for valid substrings
        int maxLen = 0; // Maximum valid substring length

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i); // Push the index of '('
            } else {
                st.pop(); // Pop for ')'
                if (st.empty()) {
                    st.push(i); // Push current index as new base
                } else {
                    maxLen = max(maxLen, i - st.top()); // Calculate valid substring length
                }
            }
        }

        return maxLen;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.maxLength(S) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends