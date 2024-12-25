
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dfs(TreeNode* root,int depth){
        if(!root) return depth;
        int ans = max(dfs(root->right,depth+1),dfs(root->left,depth+1));
        return ans; 
    }
    int maxDepth(TreeNode* root) {
        TreeNode* newNode = root;
        return dfs(newNode,0);
    }
};
int main(){

}