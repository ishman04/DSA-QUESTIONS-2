#include<bits/stdc++.h>
using namespace std;

void permutations(string& str, int idx){
    if(idx == str.length()-1){
        cout << str << endl;
        return;
    }
    for(int i=idx;i<str.size();i++){
        swap(str[idx], str[i]);
        permutations(str,idx+1);
        swap(str[idx],str[i]);
    }
}

int main(){
    string s;
    cin>>s;
    permutations(s,0);
}