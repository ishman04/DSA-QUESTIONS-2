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
    int count = 0;
    int ans = -1;
    int m;

    void inorder(TreeNode* root) {
        if (!root || ans != -1) return; // stop early if found

        inorder(root->left);

        count++;
        if (count == m) {
            ans = root->val;
            return;
        }

        inorder(root->right);
    }

    int kthSmallest(TreeNode* root, int k) {
        m = k;
        inorder(root);
        return ans;
    }
};
