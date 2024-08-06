//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    if (arr.empty()) {
        return NULL;
    }
    int val = arr[0];
    int size = arr.size();

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 1; i < size; i++) {
        val = arr[i];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


// } Driver Code Ends


// struct Node {
//     int data;
//     struct Node* next;
//     Node(int x) {
//         data = x;
//         next = NULL;
//     }
// };


class Solution {
  public:
    // Function to add two numbers represented by linked list.
    void reverse(Node* head){
        Node* prev = NULL;
        Node* curr = head;
        Node* NEXT = NULL;
        while(curr){
            NEXT=curr->next;
            curr->next=prev;
            prev=curr;
            curr=NEXT;
        }
    }
    Node* addTwoLists(struct Node* num1, struct Node* num2) {
        // code here
        reverse(num1);
        reverse(num2);
        Node* temp1=num1;
        Node* temp2=num2;
        int ans1=0;
        int ans2=0;
        int k=1;
        while(temp1!=NULL){
            ans1+=k*temp1->data;
            k=k*10;
            temp1=temp1->next;
        }
        k=1;
        while(temp2!=NULL){
            ans2+=k*temp2->data;
            k=k*10;
            temp2=temp2->next;
        }
        int ans=ans1+ans2;
        cout<<ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input

    while (t--) {
        Node* num1 = buildList();
        Node* num2 = buildList();
        Solution ob;
        Node* res = ob.addTwoLists(num1, num2);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends