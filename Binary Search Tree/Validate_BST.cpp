#define ll long long int
#include<bits/stdc++.h>
using namespace std;
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
class Solution {
public:
    bool check(TreeNode* root, ll minVal, ll maxVal){ 
        if(!root) return true;
        if(root->val <= minVal || root->val >= maxVal) return false;
        return check(root->left,minVal,root->val) && check(root->right,root->val,maxVal);
    }
    bool isValidBST(TreeNode* root) {
        if(!root->left && !root->right) return true;
        return check(root,LLONG_MIN,LLONG_MAX);
    }
};