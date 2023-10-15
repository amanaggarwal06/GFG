//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//function Template for C++

//Function to reverse the queue.
class Solution
{
    public:
    void queue_rev(queue<int> &q){
        
        int size = q.size();
        //base case
        if(size == 1){
            return;
        }
        
        int value = q.front();
        q.pop();
        
        queue_rev(q);
        q.push(value);
        return;
    }
    
    queue<int> rev(queue<int> q)
    {
        // add code here.
        int size = q.size();
        
        //base case
        queue_rev(q);
        return q;
    }
};


//{ Driver Code Starts.
int main()
{
    int test;
    cin>>test; 
    while(test--)
    {
    queue<int> q; 
    int n, var; 
    cin>>n; 
    while(n--)
    {
        cin>>var; 
        q.push(var);
    }
    Solution ob;
    queue<int> a=ob.rev(q); 
    while(!a.empty())
    {
        cout<<a.front()<<" ";
        a.pop();
    }
    cout<<endl; 
    }
}
// } Driver Code Ends