//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

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
class Solution {
    
    void FindParent(Node* root, unordered_map<Node* , Node* > &parent){
        
        if(root == NULL){
            return;
        }
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            
            Node* topnode = q.front();
            q.pop();
            
            if(topnode->left != NULL){
                parent[topnode->left] = topnode;
                q.push(topnode->left);
            }
            
            if(topnode->right != NULL){
                parent[topnode->right] = topnode;
                q.push(topnode->right);
            }
        }
        
        return;
    }
    
    Node* FindTargetNode(Node* root, int target){
        
        //base case
        if(root == NULL){
            return NULL;
        }
        
        if(root->data == target){
            return root;
        }
        
        Node* left = FindTargetNode(root->left, target);
        Node* right = FindTargetNode(root->right, target);
        
        if(left == NULL){
            return right;
        }
        
        return left;
    }
    
  public:
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        unordered_map<Node* , Node* >parent;
        
        FindParent(root, parent);
        
        Node* targetnode = FindTargetNode(root, target);
        
        if(targetnode == NULL) return 0;
        
        unordered_map < Node* , bool> visited;
        queue<Node*> q;
        
        q.push(targetnode);
        visited[targetnode] = true;
        
        int time = 0;
        
        while(!q.empty()){
            
            int size = q.size();
            
            for(int i=0; i<size; i++){
                
                Node* topnode = q.front();
                q.pop();
                
                if(topnode->left != NULL && !visited[topnode->left]){
                    q.push(topnode->left);
                    visited[topnode->left] = true;
                }
                
                if(topnode->right != NULL && !visited[topnode->right]){
                    q.push(topnode->right);
                    visited[topnode->right] = true;
                }
                
                if(parent[topnode] != NULL && !visited[parent[topnode]]){
                    q.push(parent[topnode]);
                    visited[parent[topnode]] = true;
                }
            }
            
            time++;
            
        }
        
        return (time-1);
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends