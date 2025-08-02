#include<bits/stdc++.h>
using namespace std;
int main(){

}
class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;

        if(num.size() == k) return "0";

        for(int i = 0; i < num.length(); i++) {
            while(!st.empty() && k > 0 && st.top() > num[i]) {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }

        while(k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        string ans;
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());

        // Remove leading zeros
        int j = 0;
        while(j < ans.size() && ans[j] == '0') {
            j++;
        }

        ans = ans.substr(j);

        return ans.empty() ? "0" : ans;
    }
};
