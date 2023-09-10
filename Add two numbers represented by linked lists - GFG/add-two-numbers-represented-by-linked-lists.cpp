//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
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

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
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
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    Node* reverseLL(Node* head){
        
        Node* prev = NULL;
        Node* fwd = NULL;
        
        while(head != NULL){
            fwd = head->next;
            head->next = prev;
            prev = head;
            head = fwd;
        }
        return prev;
    }
    
    void insertAtTail(Node* &tail, int data){
        
        Node* temp = new Node(data);
        tail->next = temp;
        tail = temp;
    }
    
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* l1, struct Node* l2)
    {
        // code here
        Node* head1 = l1;
        Node* head2 = l2;

        //edge case
        if(head1->data == 0 && head2->data == 0){
            return head1;
        }
        
        //reversing the LL
        head1 = reverseLL(head1);
        head2 = reverseLL(head2);
        
        int sum = 0, carry = 0;
        Node* node1 = new Node(-1);
        Node* tail = node1;

        while(head1 != NULL && head2 != NULL){

            sum = head1->data + head2->data + carry;
            if(sum <= 9){
                insertAtTail(tail, sum);
            }
            else{
                insertAtTail(tail, sum%10);
            }
            head1 = head1->next;
            head2 = head2->next;
            carry = sum/10;
        }

        while(head1 != NULL){
            sum = head1->data + carry;
            if(sum <= 9){
                insertAtTail(tail, sum);
            }
            else{
                insertAtTail(tail, sum % 10);
            }
            head1 = head1->next;
            carry = sum/10;
        }

        while(head2 != NULL){
            sum = head2->data + carry;
            if(sum <= 9){
                insertAtTail(tail, sum);
            }
            else{
                insertAtTail(tail, sum%10);
            }
            head2 = head2->next;
            carry = sum/10;
        }

        if(carry){
            insertAtTail(tail, carry);
        }

        //answer LL now has to be reversed
        return reverseLL(node1->next);
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends