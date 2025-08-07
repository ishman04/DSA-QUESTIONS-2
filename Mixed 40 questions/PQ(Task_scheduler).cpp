#include<bits/stdc++.h>
using namespace std;
int main(){

}

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        for(char task: tasks) freq[task-'A']++;
        priority_queue<int> pq;
        for(int i=0;i<26;i++){
            if(freq[i]>0){
                pq.push(freq[i]);
            }
        }
        int time = 0;
        while(!pq.empty()){
            int cycle = n+1;
            vector<int> store;
            int taskCount = 0;
            while(cycle-- && !pq.empty()){
                if(pq.top()>1){
                    store.push_back(pq.top()-1);
                }
                pq.pop();
                taskCount++;
            }
            for(int &x: store){
                pq.push(x);
            }
            time+=(pq.empty() ? taskCount : n+1);
        }
        return time;
    }
};