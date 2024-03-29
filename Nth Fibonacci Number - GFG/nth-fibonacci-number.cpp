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
        int first = 1, second = 1, third = 0;
        int mod = 1000000007;
        if(n==1 || n==2){
            return 1;
        }
        
        for(int i=2; i<n; i++){
            third = (first + second) % mod ;
            first = second % mod ;
            second = third % mod ;
        }
        
        return second;
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