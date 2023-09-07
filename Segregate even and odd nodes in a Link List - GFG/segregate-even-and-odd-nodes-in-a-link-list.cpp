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
        cout << node->data <<" "; 
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
class Solution{
    
    void insertAtTail(Node* &oddTail, int value){
        
        Node* temp = new Node(value);
        oddTail->next = temp;
        oddTail = temp;
    }
    
public:
    Node* divide(int N, Node *head){
        // code here
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        //more than one Node
        
        Node* evenhead = new Node(-1); Node* evenTail = evenhead;
        Node* oddhead = new Node(-1); Node* oddTail = oddhead;
        Node* temp = head;
        
        while(temp != NULL){
            
            int value = temp->data;
            if(value % 2 == 0){
                insertAtTail(evenTail, value);
            }
            else{
                insertAtTail(oddTail, value);
            }
            
            temp = temp->next;
        }
        
        //merge even and odd LL
        
        if(evenhead->next == NULL){
            
            //empty even LL
            return oddhead->next;
        }
        
        evenTail->next = oddhead->next;
        
        head = evenhead->next;
        return head;
        
        
        
        
    }
};

//{ Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}

// } Driver Code Ends