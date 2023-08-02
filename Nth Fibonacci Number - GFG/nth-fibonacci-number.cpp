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
        
        //base case
        // if(n==0) return 0;
        // if(n==1) return 1;
        
        // //recursive case
        
        // return ( (nthFibonacci(n-1) )%1000000007 + ( nthFibonacci(n-2) ) %1000000007 )%1000000007;
        
        int first = 0, second = 1, third = n;
        
        for(int i=2; i<=n; i++){
            
            third = (first%1000000007 + second%1000000007) % 1000000007 ;
            first = second;
            second = third;
        }
        
        return third;
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