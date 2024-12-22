//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  void sortMatrixRowWiseDescending(vector<vector<int>>& matrix) {
    for (auto& row : matrix) {
        std::sort(row.begin(), row.end(), greater<int>()); 
    }
}
    int celebrity(vector<vector<int> >& mat) {
        // code here
        int ans=-1;
        int count=0;
        vector<vector<int>> matt = mat;
        sortMatrixRowWiseDescending(mat);
        for(int i=0;i<mat.size();i++){
            if(mat[i][0]==0){
                ans=i;
                count++;
            }
        }
        if(count>1) return -1;
        for(int j=0;j<matt.size();j++){
            if(matt[j][ans]==0 && j!=ans) return -1;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends