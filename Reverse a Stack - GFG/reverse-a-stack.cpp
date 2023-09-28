//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    void insertAtBottom(stack<int> &st, int num){
        
        //base case
        if(st.empty()){
            st.push(num);
            return;
        }
        
        int top = st.top();
        st.pop();
        
        //recursive calls
        insertAtBottom(st, num);
        st.push(top);
    }

    void solve(stack<int> &st){
        
        //base case
        if(st.size() == 1){
            return;
        }
        
        int top = st.top();
        st.pop();
        
        //recursive call
        solve(st);
        insertAtBottom(st, top);
    }

    void Reverse(stack<int> &st){
        int sizes = st.size();
        
        //edge case
        if(sizes == 0 || sizes == 1){
            return ;
        }
        
        solve(st);
    }
};

//{ Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int>res;
        while(St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
    }
}
// } Driver Code Ends