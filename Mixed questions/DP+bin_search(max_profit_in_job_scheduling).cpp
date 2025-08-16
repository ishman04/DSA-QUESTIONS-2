#include<bits/stdc++.h>
using namespace std;
int main(){

}
class Solution {
public:
    struct Job {
        int start, end, profit;
    };
    int f(int i,vector<Job> &jobs,vector<int> &endTimes, vector<int> &dp){
        if(i>=jobs.size()) return 0;
        if(dp[i]!=-1) return dp[i];

        int skip = f(i+1,jobs,endTimes,dp);

        int include = jobs[i].profit;

        int nextIdx = lower_bound(endTimes.begin(),endTimes.end(),jobs[i].end) - endTimes.begin();
        include += f(nextIdx, jobs, endTimes, dp);
        return dp[i] = max(skip,include);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<Job> jobs(n);

        for(int i=0;i<n;i++){
            jobs[i] = {startTime[i],endTime[i],profit[i]};
        }

        sort(jobs.begin(), jobs.end(), [](Job &a, Job &b) {
            return a.start < b.start;
        });

        vector<int> endTimes;
        for(auto &job : jobs) endTimes.push_back(job.start);

        vector<int> dp(n,-1);
        return f(0,jobs,endTimes,dp);
    }
};