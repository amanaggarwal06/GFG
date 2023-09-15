//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
    
    
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
    
    Node* Middle(Node* head){
        
        Node* slow = head;
        Node* fast = head;
        
        while(fast->next != NULL && fast != NULL){
            
            fast = fast->next;
            if(fast->next != NULL && fast != NULL){
                fast = fast->next;
            }
            else{
                break;
            }
            
            slow = slow->next;
        }
        
        return slow;
    }
    
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        //Your code here
        //edge cases
        if(head == NULL || head->next == NULL){
            return true;
        }
        
        Node* middle = Middle(head);
        middle->next = reverseLL(middle->next);
        
        Node* temp = middle->next;
        
        while(temp != NULL){
            if(temp->data != head->data){
                return false;
            }
            
            temp = temp->next;
            head = head->next;
        }
        
        return true;
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends