//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array
// of jobs with deadlines and profits
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    static bool cmp(pair<int,pair<int,int>>& a ,pair<int,pair<int,int>>& b){
        return a.first > b.first;
    }
    vector<int> JobSequencing(vector<int> &id, vector<int> &deadline,
    vector<int> &profit) {
        // code here
        int n = id.size();
        
        vector<pair<int, pair<int, int>>> jobs;
        for(int i = 0; i < n; i++) {
            jobs.push_back({profit[i], {deadline[i], id[i]}});
        }
        
        sort(jobs.begin(), jobs.end(), cmp);
        
        int maxDeadline = 0;
        for(int i = 0; i < n; i++) {
            maxDeadline = max(maxDeadline, jobs[i].second.first);
        }
        
        vector<bool> timeSlot(maxDeadline + 1, false);
        int totalProfit = 0;
        int count = 0;
        vector<int> resultJobs;
        
        for(int i = 0; i < n; i++) {
            for(int j = jobs[i].second.first; j > 0; j--) {
                if (!timeSlot[j]) {
                    timeSlot[j] = true;
                    totalProfit += jobs[i].first;
                    resultJobs.push_back(jobs[i].second.second);
                    count++;
                    break;
                }
            }
        }
        vector<int> ans(2);
        ans[0]=count;ans[1]=totalProfit;
        return ans;
    }
};


//{ Driver Code Starts.
//            Driver program to test methods
int main() {
    int t;
    // testcases
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> jobIDs, deadlines, profits;
        string temp;
        getline(cin, temp);
        istringstream ss1(temp);
        int x;
        while (ss1 >> x)
            jobIDs.push_back(x);

        getline(cin, temp);
        istringstream ss2(temp);
        while (ss2 >> x)
            deadlines.push_back(x);

        getline(cin, temp);
        istringstream ss3(temp);
        while (ss3 >> x)
            profits.push_back(x);

        int n = jobIDs.size();

        Solution obj;
        vector<int> ans = obj.JobSequencing(jobIDs, deadlines, profits);
        cout << ans[0] << " " << ans[1] << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends