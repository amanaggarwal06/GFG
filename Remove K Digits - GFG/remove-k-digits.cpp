//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string removeKdigits(string S, int k) {
        
        string ans;
        int length = S.length();
        stack <char> st;
        
        for(int i=0; i< length; i++){
            
            char ch = S[i];
            
            while( !st.empty() && ch < st.top() && k>0){
               st.pop();
                k--;
            }
            
            if(st.empty() && ch != '0'){
                st.push(ch);
            }
            else if( !st.empty() ){
                st.push(ch);
            }
        }
        
        while( !st.empty() && k>0){
            st.pop();
            k--;
        }
        
        if(st.empty()){
            return "0";
        }
        
        while(!st.empty()){
            ans.push_back( st.top() );
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution obj;
        cout << obj.removeKdigits(S, K) << endl;
    }
    return 0;
}

// } Driver Code Ends