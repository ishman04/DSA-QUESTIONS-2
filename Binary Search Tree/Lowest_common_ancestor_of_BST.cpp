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
    TreeNode* LCA(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root || root == p || root == q) return root;
        TreeNode* l = LCA(root->left,p,q);
        TreeNode* r = LCA(root->right,p,q);
        if(l && r){
            return root;
        }
        return (l) ? l : r;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return LCA(root,p,q);
    }
};