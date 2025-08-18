#include<bits/stdc++.h>
using namespace std;
int main(){

}
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int lo = matrix[0][0];
        int hi = matrix[n-1][n-1];
        while(lo<hi){
            int count = 0;
            int j = n-1;
            int mid = lo + (hi-lo)/2;
            for(int i=0;i<n;i++){
                while(j>=0 && matrix[i][j]>mid){
                    j--;
                }
                count += (j+1);
            }
            if(count<k) lo = mid+1;
            else hi = mid;
        }
        return hi;
    }
};