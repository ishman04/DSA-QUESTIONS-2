//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    int precedence(char op){
        if(op=='^') return 3;
        if(op=='*' || op=='/') return 2;
        if(op=='+' || op=='-') return 1;
        return 0;
    }
    string infixToPostfix(string s) {
        // Your code her
        string result="";
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(isalnum(s[i])){
                result += s[i];
            }
            else if(s[i] == '('){
                st.push(s[i]);
            }
            else if(s[i]==')'){
                while(!st.empty() && st.top()!='('){
                    char op = st.top();
                    st.pop();
                    result += op;
                }
                st.pop();
            }
            else{
                while(!st.empty() && precedence(st.top()) >= precedence(s[i])){
                    char op = st.top();
                    st.pop();
                    result+=op;
                }
                st.push(s[i]);
            }
        }
        while(!st.empty()){
            char op = st.top();
            st.pop();
            result+=op;
        }
        return result;
    }
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends