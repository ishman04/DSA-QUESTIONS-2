#include<bits/stdc++.h>
using namespace std;
int main(){

}
// The structure of the binary tree is as follows
struct Node
{
    int data;
    Node* left;
    Node* right;
};


class Solution {
  public:
    /*You are required to complete this method*/
    vector<int> ans;
    void f(Node* root,int count){
        if(!root) return;
        if(!root->left && !root->right) {
            ans.push_back(count);
            return;
        }
        f(root->left,count+1);
        f(root->right,count+1);
    }
    bool check(Node *root) {
        // Your code here
        f(root,0);
        sort(ans.begin(),ans.end());
        return ans[0] == ans[ans.size()-1] ? true : false;
    }
};