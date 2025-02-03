//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/
#define dd double
class Solution {
  public:
    // Function to get the maximum total value in the knapsack.
    static bool cmp(pair<dd,pair<int,int>>& a, pair<dd,pair<int,int>>& b){
        return a.first>b.first;
    }
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // Your code here
        vector<pair<dd,pair<int,int>>> v;
        for(int i=0;i<val.size();i++){
            dd ratio = (dd)val[i]/(dd)wt[i];
            v.push_back({ratio,{val[i],wt[i]}});
        }
        sort(v.begin(),v.end(),cmp);
        dd ans=0;
        int i=0;
        while(capacity>=0 && i<v.size()){
            if(capacity - v[i].second.second >=0){
                capacity -= v[i].second.second;
                ans += v[i].second.first;
            }
            else{
                ans += v[i].first * capacity;
                capacity = -1;
                break;
            }
            i++;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    // taking testcases
    cin >> t;
    cin.ignore(); // to ignore the newline after the number of test cases
    cout << setprecision(6) << fixed;

    while (t--) {
        // Reading the value array
        vector<int> values;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            values.push_back(number);
        }

        // Reading the weight array
        vector<int> weights;
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            weights.push_back(number);
        }

        // Reading the capacity
        int w;
        cin >> w;
        cin.ignore(); // to ignore the newline after capacity

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(values, weights, w) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends