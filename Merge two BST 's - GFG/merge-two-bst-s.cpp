//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};





// Function to Build Tree
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));

   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}



// } Driver Code Ends
/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
// class BSTiterator {
    
// private : 
//     stack<Node*> st;
    
// public:

//     BSTiterator(Node* root){
//         pushAll(root);
//     }
    
//     void pushAll(Node* root){
        
//         while(root != NULL){
//             st.push(root);
//             root = root->left;
//         }
//     }
    
//     bool hasNext(){
//         return (!st.empty());
//     }
    
//     int Next(){
        
//         Node* top_node = st.top();
//         st.pop();
        
//         pushAll(top_node->right);
        
//         return top_node->data;
//     }
// };

class Solution
{
    
    void flattenLL(Node* root, Node* &head1){
        
        //base case
        if(root == NULL) return;
        
        flattenLL(root->right, head1);
        
        root->right = head1;
        Node* left_subtree = root->left;
        
        root->left = NULL;
        head1 = root;
        
        flattenLL(left_subtree, head1);
        
    }
    
    Node* mergeTwoSortedLL(Node* head1, Node* head2){
        
        //edge cases
        if(head1 == NULL) return head2;
        else if(head2 == NULL) return head1;
        
        Node* result = head1;
        Node* next = head1->right;
        
        while(next != NULL && head2 != NULL){
            
            if(head2->data >= head1->data &&  head2->data < next->data){
                
                head1->right = head2;
                Node* fwd = head2->right;
                
                head2->right = next;
                head2 = fwd;
            }
            
            head1 = head1->right;
            next = head1->right;
        }
        
        if(next == NULL){
            head1->right = head2;
        }
        
        return result;
    }
    
    void getElements(Node* head, vector<int> &ans){
        
        //edge case
        if(head == NULL){
        }
        
        while(head != NULL){
            ans.push_back(head->data);
            head = head->right;
        }
        
    }
    
    public:
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2)
    {
       //Your code here
       
       //brute->
       // inorder in BST1, inorder in BST2
       //merge 2 vector in sorted way
       //T.C-> O(n)
       //S.C-> O(2n) for 2 extra vectors
       
       //optimal Approach
       
    //   vector<int> ans;
    //   BSTiterator tree1(root1), tree2(root2);
       
    //   //edge cases
    //   if(root1 == NULL && root2 == NULL){
    //       return ans;
    //   }
       
    //   else if(root1 == NULL){
           
    //       while(tree2.hasNext()){
    //           ans.push_back(tree2.Next());
    //       }
           
    //       return ans;
    //   }
    //   else if(root2 == NULL){
           
    //       while(tree1.hasNext()){
    //           ans.push_back(tree1.Next());
    //       }
           
    //       return ans;
    //   }
       
    //   int val1 = tree1.Next(), val2 = tree2.Next();
       
    //   while(tree1.hasNext() && tree2.hasNext()){
           
    //       if( ans.size() != 0 && val1 == ans.back()){
    //           val1 = tree1.Next();
    //       }
           
    //       if(ans.size() != 0 && val2 == ans.back()){
    //           val2 = tree2.Next();
    //       }
           
    //       if(val1 < val2 ){
    //           ans.push_back(val1);
               
    //         //   if(tree1.hasNext()){
    //         //       val1 = tree1.Next();
    //         //   }
    //       }
    //       else if(val1 > val2){
    //           ans.push_back(val2);
               
    //         //   if(tree2.hasNext()){
    //         //       val2 = tree2.Next();
    //         //   }
    //       }
    //       else{
               
    //           ans.push_back(val1);
    //           ans.push_back(val2);
               
    //         //   if(tree1.hasNext()) val1 = tree1.Next();
    //         //   if(tree2.hasNext()) val2 = tree2.Next();
    //       }
    //   }
       
    // //   if(val1 != ans.back()){
    // //       ans.push_back(val1);
    // //   }
       
    //   while(tree1.hasNext()){
           
    //       val1 = tree1.Next();
    //       ans.push_back(val1);
           
    //   }
       
    // //   if(val2 != ans.back()){
    // //       ans.push_back(val2);
    // //   }
       
    //   while(tree2.hasNext()){
           
    //       val2 = tree2.Next();
    //       ans.push_back(val2);
           
    //   }
       
    //   return ans;
    
    //--------------------------------------------------------> 
    //Approach 2
    
    vector<int> ans;
    
    //edge case
    if(root1 == NULL && root2 == NULL){
        return ans;
    }
    else if(root1 == NULL){
        
        getElements(root2, ans);
        return ans;
    }
    else if(root2 == NULL){
        
        getElements(root1, ans);
        return ans;
    }
    
    
    Node* head1 = NULL;
    Node* head2 = NULL;
    
    flattenLL(root1, head1);
    flattenLL(root2, head2);
    
    if(head1->data > head2->data){
        Node* temp = head1;
        head1 = head2;
        head2 = temp;
    }
    
    Node* mergedLL_head_node = mergeTwoSortedLL(head1, head2);
    
    getElements(mergedLL_head_node, ans);
    return ans;
       
    }
};

//{ Driver Code Starts.
int main() {

   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root1 = buildTree(s);

       getline(cin, s);
       Node* root2 = buildTree(s);
    
       // getline(cin, s);
       Solution obj;
       vector<int> vec = obj.merge(root1, root2);
       for(int i=0;i<vec.size();i++)
            cout << vec[i] << " ";
        cout << endl;
       ///cout<<"~"<<endl;
   }
   return 0;
}
// } Driver Code Ends