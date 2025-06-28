#include<bits/stdc++.h>
using namespace std;
int main(){

}
struct Node
{
  char data;
  struct Node* left;
  struct Node* right;
};
class Solution {
  public:
    unordered_map<string, int> subtreeMap;
    bool foundDuplicate = false;

    string serialize(Node* root) {
        if (!root) return "#";

        string left = serialize(root->left);
        string right = serialize(root->right);

        string subtree = to_string(root->data) + "," + left + "," + right;
        
        if (left != "#" || right != "#") {
            subtreeMap[subtree]++;
            if (subtreeMap[subtree] == 2) {
                foundDuplicate = true;
            }
        }

        return subtree;
    }

    int dupSub(Node *root) {
        subtreeMap.clear();
        foundDuplicate = false;
        serialize(root);
        return foundDuplicate ? 1 : 0;
    }
};
