#include<bits/stdc++.h>
using namespace std;
int main(){

}

class Solution {
public:
    map<string, priority_queue<string, vector<string>, greater<string>>> mp;
    vector<string> ans;

    void dfs(string from) {
        auto &pq = mp[from];
        while (!pq.empty()) {
            string next = pq.top();
            pq.pop();
            dfs(next);
        }
        ans.push_back(from); // add after exploring all destinations
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto &t : tickets) {
            mp[t[0]].push(t[1]);
        }
        dfs("JFK");
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
