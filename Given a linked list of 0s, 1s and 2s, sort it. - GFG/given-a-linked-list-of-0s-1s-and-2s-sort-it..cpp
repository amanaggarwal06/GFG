//{ Driver Code Starts
#include <bits/stdc++.h>

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

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    void insertAtTail(Node* &Tail, int data){
        
        Node* temp = new Node(data);
        Tail->next = temp;
        Tail = temp;
        
    }
    
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        //edge cases
        if(head == NULL || head->next == NULL){
            return head;
        }
        else if(head->next->next == NULL){
            
            if(head->data <= head->next->data){
                return head;
            }
            else{
                swap(head->data, head->next->data);
                return head;
            }
        }
        
        // Add code here
        Node*temp = head;
        Node* zeroHead = new Node(-1); Node* zeroTail = zeroHead;
        Node* oneHead = new Node(-1); Node* oneTail = oneHead;
        Node* twoHead = new Node(-1); Node* twoTail = twoHead;
        
        while(temp != NULL){
            
            int value = temp->data;
            
            if(value == 0){
                insertAtTail(zeroTail, 0);
            }
            else if(value == 1){
                insertAtTail(oneTail, 1);
            }
            else if(value == 2){
                insertAtTail(twoTail, 2);
            }
            
            temp = temp->next;
        }
        
        //Merge all these three LL
        
        zeroTail->next = oneHead->next;
        
        if(oneHead->next == NULL){
            zeroTail->next = twoHead->next;
        }
        
        oneTail->next = twoHead->next;
        
        return zeroHead->next;
        
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends