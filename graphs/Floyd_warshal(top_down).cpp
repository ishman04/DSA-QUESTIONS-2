//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
    // 3D DP array to store minimum distances
    // dp[k][i][j] represents shortest path from i to j using vertices {0,1,...,k} as intermediates
    int dp[101][101][101];
    int V; // number of vertices
    
    int solve(vector<vector<int>>& matrix, int k, int i, int j) {
        // Base case: if k == -1, return direct edge weight
        if (k == -1) {
            return matrix[i][j];
        }
        
        // If already computed
        if (dp[k][i][j] != -2) {
            return dp[k][i][j];
        }
        
        // Get the shortest path without using vertex k
        int withoutK = solve(matrix, k-1, i, j);
        
        // Get the shortest path using vertex k as intermediate
        int withK = INT_MAX;
        int firstHalf = solve(matrix, k-1, i, k);
        int secondHalf = solve(matrix, k-1, k, j);
        
        // If both paths exist, calculate total distance through k
        if (firstHalf != INT_MAX && secondHalf != INT_MAX) {
            withK = firstHalf + secondHalf;
        }
        
        // Return minimum of paths with and without using vertex k
        dp[k][i][j] = min(withoutK, withK);
        return dp[k][i][j];
    }
    
public:
    void shortestDistance(vector<vector<int>>& matrix) {
        V = matrix.size();
        
        // Initialize dp array with -2 (to distinguish from -1 in the matrix)
        for (int k = 0; k < V; k++) {
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) {
                    dp[k][i][j] = -2;
                }
            }
        }
        
        // Convert matrix[i][j] = -1 to INT_MAX for no edge case
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (matrix[i][j] == -1) {
                    matrix[i][j] = INT_MAX;
                }
            }
        }
        
        // Calculate shortest paths for all pairs
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                int result = solve(matrix, V-1, i, j);
                // Convert back INT_MAX to -1 for no path
                matrix[i][j] = (result == INT_MAX) ? -1 : result;
            }
        }
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }
        Solution obj;
        obj.shortestDistance(matrix);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends