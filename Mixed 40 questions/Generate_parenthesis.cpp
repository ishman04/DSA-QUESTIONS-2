#include<bits/stdc++.h>
using namespace std;
int main(){

}
class Solution {
public:
    vector<string> res;
    void f(int open, int closed,string ans){
        if(open>closed) return;
        if(open==0 && closed==0){
            res.push_back(ans);
            return;
        }
        if (open > 0) f(open - 1, closed, ans + '(');
        if (closed > 0) f(open, closed - 1, ans + ')');
    }
    vector<string> generateParenthesis(int n) {
        f(n,n,"");
        return res;
    }
};