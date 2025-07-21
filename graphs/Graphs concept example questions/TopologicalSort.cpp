//Course schedule

#include<bits/stdc++.h>
using namespace std;
int main(){

}

class Solution {
public:
    bool canFinish(int num, vector<vector<int>>& arr) {
        vector<vector<int>> graph(num);
        vector<int> indegree(num);
        for (const auto& p : arr) {
            graph[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }
        
        queue<int> q;
        for(int i=0;i<num;i++){
            if(indegree[i]==0) q.push(i);
        }
        int visited = 0;
        while(!q.empty()){
            int course = q.front();
            q.pop();
            visited++;

            for(int neigh: graph[course]){
                indegree[neigh]--;
                if(indegree[neigh]==0) q.push(neigh);
            }
        }
        return visited == num;
    }
};
