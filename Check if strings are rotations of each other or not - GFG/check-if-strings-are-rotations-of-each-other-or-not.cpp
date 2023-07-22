//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if two strings are rotations of each other or not.
    bool areRotations(string s1,string s2)
    {
        // Your code here
        int length1 = s1.length();
        int length2 = s2.length();
        
        if(length1 != length2){
            return false;
        }
        
        if(s1==s2){
            return true;
        }
        
        queue<int> q,q1;
        
        for(int i=0; i< length1; i++){
            q.push(s1[i]);
            q1.push(s2[i]);
        }
        
        for(int i=0; i< length1; i++){
            q.push(q.front());
            q.pop();
            
            if(q==q1){
                return true;
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s1;
        string s2;
        cin>>s1>>s2;
        Solution obj;
        cout<<obj.areRotations(s1,s2)<<endl;

    }
    return 0;
}

// } Driver Code Ends