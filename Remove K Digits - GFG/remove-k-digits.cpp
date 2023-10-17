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
        
        for(int i=0; i< length; i++){
            
            char ch = S[i];
            
            while( !ans.empty() && ch < ans.back() && k>0){
                ans.pop_back();
                k--;
            }
            
            if(ans.empty() && ch != '0'){
                ans.push_back(ch);
            }
            else if( !ans.empty() ){
                ans.push_back(ch);
            }
        }
        
        while( !ans.empty() && k>0){
            ans.pop_back();
            k--;
        }
        
        if(ans.empty()){
            return "0";
        }
        
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