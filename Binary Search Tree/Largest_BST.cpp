#include<bits/stdc++.h>
using namespace std;
int main(){

}


struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int data) {
        data = data;
        left = right = NULL;
    }
};

class Solution {
  public:
    int maxBSTSize = 0;

    struct Info {
        bool isBST;
        int size;
        int mindata;
        int maxdata;

        Info(bool isBSTVal, int sizeVal, int mindataVal, int maxdataVal) {
        isBST = isBSTVal;
        size = sizeVal;
        mindata = mindataVal;
        maxdata = maxdataVal;
    }
    };

    Info dfs(Node* root) {
        if (!root) {
            return Info(true, 0, INT_MAX, INT_MIN); 
        }

        Info left = dfs(root->left);
        Info right = dfs(root->right);

        if (left.isBST && right.isBST && root->data > left.maxdata && root->data < right.mindata) {
            int size = left.size + right.size + 1;
            maxBSTSize = max(maxBSTSize, size);
            return Info(true, size, min(root->data, left.mindata), max(root->data, right.maxdata));
        }

        return Info(false, 0, 0, 0); 
    }

    int largestBst(Node* root) {
        dfs(root);
        return maxBSTSize;
    }
};