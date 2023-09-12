//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    Node *next;
    Node *arb;

    Node(int x) {
        data = x;
        next = NULL;
        arb = NULL;
    }
};



// } Driver Code Ends
class Solution
{
     void insertAtTail(Node* &tail, int data){

        Node* temp = new Node(data);
            tail->next = temp;
            tail = temp;
    }
    
    public:
    Node *copyList(Node *head)
    {
        //Write your code here
        //edge case
        if(head == NULL){
            return NULL;
        }
        else if(head->next == NULL){
            Node* temp = new Node(head->data);
            return temp;
        }

        //more than 2 nodes in LL
        Node* cloneHead = new Node(-1);
        Node* tail = cloneHead; 
        Node* temp = head;

        while(temp != NULL){

            insertAtTail(tail, temp->data);
            temp = temp->next;
        }

        cloneHead = cloneHead->next;

        // joining oldLL and newLL
        Node* head1 = head;
        Node* head2 = cloneHead;

        while(head1 != NULL && head2 != NULL){
            Node* fwd = head1->next;

            head1->next = head2;
            
            head1 = fwd;

            Node* next = head2->next;
            head2->next = head1;
            
            head2 = next;
        }

        // assign random pointers values in CloneLL
        head1 = head;
        head2 = cloneHead;

        while(head1 != NULL && head2 != NULL){

            Node* rand = head1->arb;
            
            if(rand != NULL){
                head2->arb = rand->next;
            }
            else{
                head2->arb = rand;
            }

            head1 = head1->next;

            if(head1 != NULL){
                head1 = head1->next;
            }

            head2 = head2->next;
            if(head2 != NULL){
                head2 = head2->next;
            }
        }

        //make the original LL same as in initial position it was
        head1 = head; head2 = cloneHead;

        while(head1 != NULL && head2 != NULL){

            head1->next = head2->next;
            head1 = head1->next;

            if(head1 != NULL){
                head2->next = head1->next;
            }
           
            head2 = head2->next;
        }

        return cloneHead;
    }

};

//{ Driver Code Starts.


void print(Node *root) {
    Node *temp = root;
    while (temp != NULL) {
        int k;
        if (temp->arb == NULL)
            k = -1;
        else
            k = temp->arb->data;
        cout << temp->data << " " << k << " ";
        temp = temp->next;
    }
}


void append(Node **head_ref, Node **tail_ref, int new_data) {

    Node *new_node = new Node(new_data);
    if (*head_ref == NULL) {
        *head_ref = new_node;
    } else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

bool validation(Node *head, Node *res) {


    Node *temp1 = head;
    Node *temp2 = res;

    int len1 = 0, len2 = 0;
    while (temp1 != NULL) {
        len1++;
        temp1 = temp1->next;
    }
    while (temp2 != NULL) {
        len2++;
        temp2 = temp2->next;
    }

    /*if lengths not equal */

    if (len1 != len2) return false;

    temp1 = head;
    temp2 = res;
    map<Node*,Node*> a;
    while (temp1 != NULL) {
        
        if(temp1==temp2)
            return false;
        
        if (temp1->data != temp2->data) return false;
        if (temp1->arb != NULL and temp2->arb != NULL) {
            if (temp1->arb->data != temp2->arb->data)
                return false;
        } else if (temp1->arb != NULL and temp2->arb == NULL)
            return false;
          else if (temp1->arb == NULL and temp2->arb != NULL)
            return false;
        a[temp1]=temp2;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    

    temp1 = head;
    temp2 = res;
    while (temp1 != NULL) {
        
        if (temp1->arb != NULL and temp2->arb != NULL) {
            if (a[temp1->arb] != temp2->arb) return false;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return true;
}



int main() {

    int T, i, n, l, k;
    Node *generated_addr = NULL;
     /*reading input stuff*/
    cin >> T;
    while (T--) {
        generated_addr = NULL;
        struct Node *head = NULL, *tail = NULL;
        struct Node *head2 = NULL, *tail2 = NULL;
        cin >> n >> k;
        for (i = 1; i <= n; i++) {
            cin >> l;
            append(&head, &tail, l);
            append(&head2, &tail2, l);
        }
         for (int i = 0; i < k; i++) {
            int a, b;
            cin >> a >> b;

            Node *tempA = head;
            Node *temp2A = head2;
            int count = -1;

            while (tempA != NULL) {
                count++;
                if (count == a - 1) break;
                tempA = tempA->next;
                temp2A = temp2A->next;
            }
            Node *tempB = head;
            Node *temp2B = head2;
            count = -1;

            while (tempB != NULL) {
                count++;
                if (count == b - 1) break;
                tempB = tempB->next;
                temp2B = temp2B->next;
            }

            // when both a is greater than N
            if (a <= n){
                tempA->arb = tempB;
                temp2A->arb = temp2B;
            }
        }
        /*read finished*/

        generated_addr = head;
        Solution ob;
        struct Node *res = ob.copyList(head);
        if(validation(head2,res)&&validation(head,res))
            cout << validation(head2, res) << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}
// } Driver Code Ends