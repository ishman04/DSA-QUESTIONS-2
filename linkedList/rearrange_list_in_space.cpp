/* Following is the Linked list node structure */
#include<bits/stdc++.h>
using namespace std;
int main(){

}

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};



class Solution {
  public:
    void reorderList(Node* head) {
        // Your code here
        if (!head || !head->next || !head->next->next) return;

        // Step 1: Find the middle of the list
        Node* slow = head;
        Node* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half
        Node* prev = nullptr;
        Node* curr = slow->next;
        while (curr) {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        slow->next = nullptr; // break the first half

        // Step 3: Merge two halves
        Node* first = head;
        Node* second = prev;
        while (second) {
            Node* tmp1 = first->next;
            Node* tmp2 = second->next;

            first->next = second;
            second->next = tmp1;

            first = tmp1;
            second = tmp2;
            
        }
    }
};