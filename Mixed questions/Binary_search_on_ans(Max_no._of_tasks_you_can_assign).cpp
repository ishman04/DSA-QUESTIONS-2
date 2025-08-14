#include<bits/stdc++.h>
using namespace std;
int main(){

}

class Solution {
public:
    bool canAssign(int k,vector<int>& tasks, vector<int>& workers, int pills, int strength){
        multiset<int> w;
        int n= tasks.size();
        int m= workers.size();
        for(int i=m-k;i<m;i++){
            w.insert(workers[i]);
        }

        int pillsLeft = pills;
        for(int i=k-1;i>=0;i--){
            auto it = prev(w.end());
            if(*it >= tasks[i]) w.erase(it);
            else{
                auto it2 = w.lower_bound(tasks[i]-strength);
                if(it2 == w.end() || pillsLeft==0) return false;
                w.erase(it2);
                pillsLeft--;
            }
        }
        return true;
    }
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(),tasks.end());
        sort(workers.begin(),workers.end());
        int l = 0, r = min((int)(tasks.size()),(int)(workers.size())), ans =0;
        while(l<=r){
            int m=(l+r)/2;
            if(canAssign(m,tasks,workers,pills,strength)){
                ans = m;
                l = m+1;
            }
            else r = m-1;
        }
        return ans;
    }
    
};