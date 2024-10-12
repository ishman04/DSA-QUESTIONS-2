//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    vector<pair<int, int>> dir = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};
    
    int minStepToReachTarget(vector<int>& KnightPos, vector<int>& TargetPos, int N)
    {
        if (KnightPos[0] == TargetPos[0] && KnightPos[1] == TargetPos[1]) {
            return 0;
        }

        vector<vector<bool>> visited(N+1, vector<bool>(N+1, false));
        
        queue<pair<pair<int, int>, int>> q;
        q.push({{KnightPos[0], KnightPos[1]}, 0});
        visited[KnightPos[0]][KnightPos[1]] = true;
        
        while (!q.empty()) {
            auto current = q.front();
            q.pop();
            
            int x = current.first.first;
            int y = current.first.second;
            int steps = current.second;
            
            for (auto d : dir) {
                int newX = x + d.first;
                int newY = y + d.second;
                
                if (newX > 0 && newY > 0 && newX <= N && newY <= N && !visited[newX][newY]) {
                    if (newX == TargetPos[0] && newY == TargetPos[1]) {
                        return steps + 1;
                    }
                    visited[newX][newY] = true;
                    q.push({{newX, newY}, steps + 1});
                }
            }
        }
        return -1;
    
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends