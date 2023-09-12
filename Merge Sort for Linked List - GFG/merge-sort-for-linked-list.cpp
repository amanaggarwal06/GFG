//{ Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
    
    Node* getMiddle(Node* head){

       Node* slow = head;
        Node* fast = head->next;

        while( fast != NULL && fast->next != NULL ){
            fast = fast->next;

            if(fast != NULL){
                fast = fast->next;
            }

            slow = slow->next;
        }

        return slow;
    }

    Node* merge(Node* left, Node* right){

        if(left == NULL){
            return right;
        }
        else if(right == NULL){
            return left;
        }

        Node* ans = new Node(-1);
        Node* tail = ans;

        while(left != NULL && right != NULL){

            if(left->data <= right->data){
                tail->next = left;
                tail = left;
                left = left->next;
            }
            else{
                tail->next =  right;
                tail = right;
                right = right->next;
            }
        }
        
        while(left != NULL){
            tail->next = left;
            tail = left;
            left = left->next;
            
        }
        
        while(right != NULL){
            tail->next =  right;
            tail = right;
            right = right->next;
            
        }
        return ans->next;

    }
    
  public:
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        // your code here
        
        //edge cases
        if(head == NULL || head->next == NULL){
            return head;
        }
        // else if(head->next->next == NULL){
        //     if(head->val <= head->next->val){
        //         return head;
        //     }
        //     else{
        //         ListNode* fwd = head->next;
        //         fwd->next = head;
        //         head->next = NULL;
        //         head = fwd;
        //         return head;
        //     }
        // }

        //more than 2 nodes
        Node* mid = getMiddle(head);
        Node* left = head;
        Node* right = mid->next;
        mid->next = NULL;
        left = mergeSort(left);
        right = mergeSort(right);

        //merge 2 sorted LL
        Node* result =  merge(left, right);
        return result;
    }
};


//{ Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}
// } Driver Code Ends