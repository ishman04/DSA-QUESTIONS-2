//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//Back-end complete function Template for C++

class Solution{
    public:
    vector<int> findLeastGreater(vector<int>& arr, int n) {
        multiset<int> st;
        for(int i=0;i<arr.size();i++){
            st.insert(arr[i]);
        }
        vector<int> ans;
        for(int i=0;i<arr.size();i++){
            auto k = st.find(arr[i]);
            st.erase(k);
            auto it = st.upper_bound(arr[i]);
            if(it != st.end()){
                for (; it != st.end(); ++it) {
                ans.push_back(*it);
                break;
                }
            }
            else ans.push_back(-1);
        }
        return ans;
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
	    cin >> n;
	    vector<int>arr(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findLeastGreater(arr, n);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout <<endl;
	
cout << "~" << "\n";
}
	return 0;
}

// } Driver Code Ends