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
    unordered_map<TreeNode*,int> dp;
    int dfs(TreeNode* root){
        if(!root) return 0;
        if(!root->left && !root->right) return root->val;
        if(dp[root]) return dp[root];
        int sum = root->val + max(dfs(root->left),dfs(root->right));
        return dp[root] = sum;

    }
    int maxPathSum(TreeNode* root) {
        if (!root) return 0;
        int ans = INT_MIN;
        ans = max(ans, dfs(root)); 
        maxPathSum(root->left);
        maxPathSum(root->right);
        return ans;
    }
};