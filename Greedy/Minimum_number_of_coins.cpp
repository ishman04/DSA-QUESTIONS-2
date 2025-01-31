//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> minPartition(int n)
    {
        // code here
        vector<int> arr;
        arr.push_back(1);arr.push_back(2);arr.push_back(5);
        arr.push_back(10);arr.push_back(20);arr.push_back(50);
        arr.push_back(100);arr.push_back(200);arr.push_back(500);arr.push_back(2000);
        int i=9;
        vector<int> coins;
        while(true){
            while(n-arr[i]>=0){
                n=n-arr[i];
                coins.push_back(arr[i]);
            }
            while(n-arr[i]<0){
                i--;
            }
            if(n==0){
             break;
            }
        }
        return coins;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends