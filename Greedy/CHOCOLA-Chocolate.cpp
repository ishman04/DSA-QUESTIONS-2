#include<bits/stdc++.h>
using namespace std;
int main(){
    int m,n;
    cin>>m>>n;
    int rows = m-1;
    int cols = n-1;
    vector<int> hs(rows);
    vector<int> vs(cols);

    int i,j;
    for(i=0;i<rows;i++) cin>>hs[i];
    for(j=0;j<cols;j++) cin>>vs[j];

    sort(hs.rbegin(),hs.rend());
    sort(vs.rbegin(),vs.rend());

    i = 0;j = 0;
    int cost = 0;
    int hor_part = 1, ver_part = 1;
    while(i<rows && j<cols){
        if(vs[j]>=hs[i]){
            cost += vs[j]*ver_part;
            hor_part++;
            j++;
        }
        else{
            cost += hs[i]*hor_part;
            ver_part++;
            i++;
        }
    }
    while(i<rows){
        cost += hs[i]*hor_part;
        ver_part++;
        i++;
    }
    while(j<cols){
        cost += vs[j]*ver_part;
        hor_part++;
        j++;
    }
    cout<<cost;
}