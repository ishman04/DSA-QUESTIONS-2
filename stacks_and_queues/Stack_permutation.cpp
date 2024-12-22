//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int isStackPermutation(int N,vector<int> &A,vector<int> &B){
        stack<int> middle;
        int j=0;
        for(int i=0;i<A.size();i++){
            middle.push(A[i]);
            while(!middle.empty() && middle.top()==B[j]){
                middle.pop();
                j++;
            }
        }
        return middle.empty() ? 1 : 0;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n),b(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        Solution ob;
        cout<<ob.isStackPermutation(n,a,b)<<endl;
    
cout << "~" << "\n";
}
    
    return 0;
}
// } Driver Code Ends