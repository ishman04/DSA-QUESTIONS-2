#include<bits/stdc++.h>
using namespace std;
int main(){

}

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& arr) {
        vector<vector<int>> gr(numCourses);
        vector<int> indegree(numCourses,0);
        for(int i=0;i<arr.size();i++){
            gr[arr[i][1]].push_back(arr[i][0]);
            indegree[arr[i][0]]++;
        }
        queue<int> q;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0) q.push(i);
        }
        int count=0;
        while(!q.empty()){
            auto ele = q.front();
            q.pop();
            count++;
            for(auto n: gr[ele]){
                indegree[n]--;
                if(indegree[n]==0) q.push(n);
            }
        }
        return count==numCourses;
    }
};