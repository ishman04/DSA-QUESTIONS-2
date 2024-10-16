//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        vector<int> minimumTime(int n,vector<vector<int>> &edges,int m)
        {
            // code here 
            vector<int> tim(n,0);
            vector<int> indegree(n,0);
            vector<vector<int>> graph(n);
            for(int i=0;i<m;i++){
                int x = edges[i][0];
                int y = edges[i][1];
                graph[x-1].push_back(y-1);
            }
            for(int i=0;i<m;i++){
                indegree[edges[i][1]-1]++;
            }
            queue<int> q;
            for(int i=0;i<n;i++){
                if(indegree[i]==0) q.push(i);
            }
            int count=0;
            while(!q.empty()){
                count++;
                int n=q.size();
                int k=0;
                while(k<n){
                    int top = q.front();
                    q.pop();
                    tim[top]=count;
                    for(auto neigh : graph[top]){
                        indegree[neigh]--;
                        if(indegree[neigh]==0) q.push(neigh);
                    }
                    k++;
                }
            }
            return tim;
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
        int m;
        cin>>m;
        vector<vector<int>> edges(m,vector<int>(2));
        for(int i=0;i<m;i++)
            cin>>edges[i][0]>>edges[i][1];
        Solution s;
        vector<int> ans=s.minimumTime(n,edges,m);
        for(auto j:ans)
            cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends