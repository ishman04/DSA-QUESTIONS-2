//{ Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        // Your code here
        stack<int> st;
        int i=0;
        int ans=0;
        while(i<S.length()){
            if(S[i]=='*' || S[i]=='/' || S[i]=='+' || S[i]=='-'){
                int x1 = (int)st.top();
                st.pop();
                int x2 = (int)st.top();
                st.pop();
                if(S[i]=='*') ans = x1*x2;
                else if(S[i]=='/') ans=x2/x1;
                else if(S[i]=='+') ans=x2+x1;
                else if(S[i]=='-') ans=x2-x1;
                st.push(ans);
                i++;
                continue;
            }
            st.push(S[i]-'0');
            i++;
            
        }
        return st.top();
    }
};

//{ Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends