  #include<bits/stdc++.h>
  using namespace std;
  int main(){
  
  }
  
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
    bool isSameTree(TreeNode* root, TreeNode* subRoot){
        if(!root && !subRoot) return true;
        if(!root || !subRoot) return false;
        if(root->val != subRoot->val) return false;
        return isSameTree(root->left,subRoot->left) && isSameTree(root->right,subRoot->right);
    }
    bool dfs(TreeNode* root, TreeNode* subRoot){
        if(!root) return false;
        if(isSameTree(root,subRoot)) return true;
        return dfs(root->left,subRoot) || dfs(root->right,subRoot);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return dfs(root,subRoot);
    }
};