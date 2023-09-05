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
    
    int lengthofLL(Node* head){
        
        if(head == NULL) return 0;
        else if(head->next == NULL) return 1;
        
        int cnt = 0;
        Node*temp = head;
        
        while(temp != NULL){
            cnt++;
            temp = temp->next;
        }
        
        return cnt;
    }
    
    Node* reverseLL(Node* head){
        if(head->next == NULL) return head;
        
        Node*prev = NULL;
        Node* curr  = head;
        
       
       while(curr != NULL){
        Node* fwd = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fwd;
       }
        
        
        return prev;
        
    }
    
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        //Your code here
        if(head == NULL || head->next == NULL){
            return true;
        }
        
        Node* slow = head;
        Node* fast = head;
        
        while(fast ->next != NULL && fast->next->next != NULL){
            
            fast = fast->next;
            
            if(fast != NULL){
                fast = fast->next;
            }
            
            slow = slow->next;
        }
        
        slow->next = reverseLL(slow->next);
        
        slow = slow->next;
        
        while(slow != NULL ){
            if(head->data != slow->data){
                return false;
            }
            
            head = head->next;
            slow = slow->next;
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