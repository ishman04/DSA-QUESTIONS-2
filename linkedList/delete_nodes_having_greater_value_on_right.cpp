//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    multiset<int> s;
    bool checkBigger(int n){
        auto it=s.upper_bound(n);
        return it!=s.end();
    }
    Node *compute(Node *head)
    {
        
        Node* temp1=head;
        while(temp1!=NULL){
            s.insert(temp1->data);
            temp1=temp1->next;
        }
        Node* dummy=new Node(0);
        dummy->next=head;
        Node* temp=dummy; 
        while(temp!=NULL && temp->next!=NULL){
            if(checkBigger(temp->next->data)){
                s.erase(s.find(temp->next->data));
                temp->next=temp->next->next;
                
            }
            else{
                s.erase(s.find(temp->next->data));
                temp=temp->next;
            }
        }
        return dummy->next;
        // your code goes here
    }
    
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends