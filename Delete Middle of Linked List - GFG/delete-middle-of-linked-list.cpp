//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

/* Function to get the middle of the linked list*/
struct Node *deleteMid(struct Node *head);
void printList(Node* node) 
{ 
	while (node != NULL) { 
		cout << node->data <<" "; 
		node = node->next; 
	}  
	cout<<"\n";
} 
int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;

		int data;
		cin>>data;
		struct Node *head = new Node(data);
		struct Node *tail = head;
		for (int i = 0; i < n-1; ++i)
		{
			cin>>data;
			tail->next = new Node(data);
			tail = tail->next;
		}
		head = deleteMid(head);
		printList(head); 
	}
	return 0; 
} 



// } Driver Code Ends


/* Link list Node:

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

// Deletes middle of linked list and returns head of the modified list
Node* deleteMid(Node* head)
{
    // Your Code Here
    if(head == NULL){
        return head;
    }
    else if(head->next == NULL){
        Node*temp = head;
        head = NULL;
        delete temp;
        return head;
    }
    else if(head->next->next == NULL){
        Node*temp = head->next;
        head->next = NULL;
        delete temp;
        return head;
    }
    
    //more than 2 nodes in LL
    int length = 0;
    Node*temp = head;
    
    while(temp!= NULL){
        temp = temp->next;
        length++;
    }
    
    int mid = length/2 + 1;
    int cnt = 1;
    temp = head;
    Node*prev = NULL;
    
    while(cnt < mid){
        prev = temp;
        temp = temp->next;
        cnt++;
    }
    
    prev->next = temp->next;
    temp->next = NULL;
    delete temp;
    return head;
}