//{ Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
}


// } Driver Code Ends
/* structure of list node:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

class Solution{
    
    void insertAtTail(Node* &tail, int data){
        
        Node* temp = new Node(data);
        tail->next = temp;
        tail = temp;
    }
    
  public:
    Node* findIntersection(Node* head1, Node* head2)
    {
        // code here
        // return the head of intersection list
        
        //edge cases
        if(head1 == NULL || head2 == NULL){
            return NULL;
        }
        else if(head1->next == NULL && head2->next == NULL){
            if(head1 != head2){
                return NULL;
            }
            else{
                return head1;
            }
        }
        
        Node* ans = new Node(-1);
        Node* tail = ans;
        unordered_map<int, bool> mp;
        
        Node* headA = head1;
        Node* headB = head2;
        
        while(headB != NULL){
            mp[headB->data] = true;
            headB = headB->next;
        }
        
        while(headA != NULL){
            
            if(mp[headA->data]){
                insertAtTail(tail, headA->data);
            }
            
            headA = headA->next;
        }
        
        
        return ans->next;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    
	    cin>> n;
	    Node* head1 = inputList(n);
	    
	    cin>>m;
	    Node* head2 = inputList(m);
	    Solution obj;
	    Node* result = obj.findIntersection(head1, head2);
	    
	    printList(result);
	    cout<< endl;
	}
	return 0;
}

// } Driver Code Ends