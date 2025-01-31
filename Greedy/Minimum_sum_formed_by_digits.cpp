//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define ll long long int
class Solution{
    public:
    long long int minSum(int arr[], int n)
    {
        // Your code goes here
        string a = "";
        string b = "";
        vector<int> v(arr,arr+n);
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++){
            if(i%2==0){
                a += to_string(v[i]);
            }
            else{
                b += to_string(v[i]);
            }
        }
        ll num1 = stoll(a);
        ll num2 = stoll(b);
        return num1+num2;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n+1];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.minSum(arr, n)<<endl;
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends