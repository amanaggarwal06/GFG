//{ Driver Code Starts
//Initial template for C++

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

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data%10; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

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

class Solution
{   
    Node* reverse(Node* head){
        
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
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        Node* temp = head;
        
        //edge case
        if(temp == NULL ){
            return head;
        }
        else if(temp->next == NULL){
            
            temp->data = temp->data + 1;
            if(temp->data <= 9){
                return head;
            }
            else{
                
                Node* node1 = new Node(-1);
                Node* tail = node1;
                insertAtTail(tail, 1);
                insertAtTail(tail, (temp->data)%10);
                return node1->next;
            }
        }
        
        temp = reverse(head);
        int sum = 0, carry = 1;
        
        Node* node1 = new Node(-1); Node* tail = node1;
        
        while(temp != NULL){
            sum = temp->data + carry;
            
            if(sum <= 9){
                insertAtTail(tail, sum);
            }
            else{
                insertAtTail(tail, sum%10);
            }
            
            carry = sum / 10;
            temp = temp->next;
        }
        
        if(carry){
            insertAtTail(tail, carry);
        }
        
        return reverse(node1->next);
        
        
        
        
        
        
        
        
        
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends