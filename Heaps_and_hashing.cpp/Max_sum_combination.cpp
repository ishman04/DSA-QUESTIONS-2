//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    static bool cmp(int &a,int &b){
        return a>b;
    }
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        // code here
        sort(A.begin(),A.end(),cmp);
        sort(B.begin(),B.end(),cmp);
        vector<int> ans;
        priority_queue<pair<int,pair<int,int>>> pq;
        set<pair<int,int>> st;
        int a = 0;
        int b = 0;
        pq.push({A[a]+B[b],{a,b}});
        while(K-- && !pq.empty()){
            auto q = pq.top();
            pq.pop();
            int sum = q.first;
            ans.push_back(sum);
            auto index = q.second;
            int i = index.first ; int j = index.second;
            if(i+1<N && st.find({i+1,j})==st.end()){
                st.insert({i+1,j});
                pq.push({A[i+1]+B[j],{i+1,j}});
            }
            if(j+1<N && st.find({i,j+1})==st.end()){
                st.insert({i,j+1});
                pq.push({A[i]+B[j+1],{i,j+1}});
            }
            
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends