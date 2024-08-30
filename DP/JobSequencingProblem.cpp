//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    static bool cmp(Job &a, Job &b) {
        return a.profit > b.profit;
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        vector<vector<int>> j;
        vector<int> slots;
        int maxlen=0;
        for(int i=0;i<n;i++){
            if(arr[i].dead>maxlen) maxlen=arr[i].dead;
        }
        slots.resize(maxlen+1,-1);
         sort(arr, arr + n, cmp);

        for(int i=0;i<n;i++){
            j.push_back({arr[i].id,arr[i].dead,arr[i].profit});
        }
        int countJobs = 0, totalProfit = 0;

        for (int i = 0; i < n; i++) {
            // Try to place the job in the latest possible slot on or before its deadline
            for (int j = arr[i].dead; j > 0; j--) {
                if (slots[j] == -1) {
                    slots[j] = arr[i].id;
                    countJobs++;
                    totalProfit += arr[i].profit;
                    break;
                }
            }
        }

        return {countJobs, totalProfit};
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends