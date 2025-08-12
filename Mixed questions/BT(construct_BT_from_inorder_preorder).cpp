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
    unordered_map<int,int> inorderIndex;
    TreeNode* construct(vector<int>& preorder, int prest,int preend,vector<int>& inorder,int inst,int inend){
        if(prest > preend || inst>inend) return nullptr;
        int rootval = preorder[prest];
        TreeNode* root = new TreeNode(rootval);
        
        int inRootIdx = inorderIndex[rootval];
        int numsLeft = inRootIdx -inst;
        root->left = construct(preorder,prest+1,prest + numsLeft,inorder,inst,inRootIdx-1);
        root->right = construct(preorder,prest+numsLeft+1,preend,inorder,inRootIdx+1,inend);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for(int i = 0;i<n;i++){
            inorderIndex[inorder[i]] = i;
        }
        return construct(preorder,0,n-1,inorder,0,n-1);

    }   
};