//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string smallestNumber(int s, int d) {
        // code here
        if(s<1 || s>9*d) return "-1";
        vector<int> dig(d,0);
        s--;
        for(int i=d-1;i>0;i--){
            if(s>9){
                dig[i] = 9;
                s-=9;
            }
            else{
                dig[i] = s;
                s=0;
            }
        }
        dig[0] = s+1;
        string ans = "";
        for(auto digit : dig){
            ans += to_string(digit);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int s, d;
        cin >> s >> d;
        Solution ob;
        cout << ob.smallestNumber(s, d) << "\n";
    }

    return 0;
}
// } Driver Code Ends