//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<int> rearrangeQueue(queue<int> &q){
        
        vector<int> v;
        queue<int> temp;
        
        int size = q.size();
        int cnt = 0;
        
        if(size %2 == 0){
            cnt = size/2;
        }
        else{
            cnt = size/2 + 1;
        }
        
        while(cnt--){
            temp.push( q.front() );
            q.pop();
        }
        
        while( !temp.empty() ){
            v.push_back( temp.front() );
            temp.pop();
            
            v.push_back(q.front());
            q.pop();
        }
        return v;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        queue<int> q;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            q.push(a);
        }
        Solution ob;
        vector<int> ans=ob.rearrangeQueue(q);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
// } Driver Code Ends