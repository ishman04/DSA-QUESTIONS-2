#include<bits/stdc++.h>
using namespace std;
int main(){

}
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};
Node* buildTree(string& s, int& i) {
        if (i >= s.size()) return NULL;

        int num = 0;
        bool isNegative = false;
        
        if (s[i] == '-') {
            isNegative = true;
            i++;
        }

        while (i < s.size() && isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
            i++;
        }

        if (isNegative) num = -num;
        Node* root = new Node(num);

        if (i < s.size() && s[i] == '(') {
            i++;
            root->left = buildTree(s, i);
            i++;
        }

        if (i < s.size() && s[i] == '(') {
            i++;
            root->right = buildTree(s, i);
            i++;
        }

        return root;
    }

    Node *treeFromString(string str) {
        int i = 0;
        return buildTree(str, i);
    }