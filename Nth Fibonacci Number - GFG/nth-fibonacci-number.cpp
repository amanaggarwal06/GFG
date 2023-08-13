//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int nthFibonacci(int n){
        // code here
        int first = 0, second = 1;
        int ans = 0;
        
        for(int i=2; i<=n; i++){
            ans = (first + second) % 1000000007;
            first = (second) % 1000000007 ;
            second = (ans) % 1000000007;
        }
        
        return ( ans % 1000000007 );
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends