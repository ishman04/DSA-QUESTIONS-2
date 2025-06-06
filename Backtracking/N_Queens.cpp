#include<bits/stdc++.h>
using namespace std;
int main(){

}
class Solution {
public:
    vector<vector<string>> v;
    bool canPlaceQueen(int n,int row,int col,vector<vector<char>>& ch){
        for(int i=0;i<n;i++){
            if(ch[row][i]=='Q' || ch[i][col]=='Q') return false;
        }
        for(int r = row-1,c=col-1;r>=0 && c>=0;r--,c--){
            if(ch[r][c]=='Q') return false;
        }
        for(int r = row-1,c=col+1;r>=0 && c<n;r--,c++){
            if(ch[r][c]=='Q') return false;
        }
        for(int r = row+1,c=col-1;r<n && c>=0;r++,c--){
            if(ch[r][c]=='Q') return false;
        }
        for(int r = row+1,c=col+1;r<n && c<n;r++,c++){
            if(ch[r][c]=='Q') return false;
        }
        return true;
    }
    void letsPlace(int n,int row,vector<vector<char>>& ch){
        if(row == n){
            string str = "";
            vector<string> val;
            for(int i=0;i<ch.size();i++){
                str = "";
                for(int j=0;j<ch.size();j++) {
                    str += ch[i][j];
                }
                val.push_back(str);
            }
            v.push_back(val);
            val.clear();
            return;
        }
        for(int i=0;i<n;i++){
            if(canPlaceQueen(n,row,i,ch)){
                ch[row][i] = 'Q';
                letsPlace(n,row+1,ch);
                ch[row][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> ch(n,vector<char>(n,'.'));
        letsPlace(n,0,ch);
        return v;
    }
};