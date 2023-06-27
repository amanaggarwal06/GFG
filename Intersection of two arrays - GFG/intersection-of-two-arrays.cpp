//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to return the count of the number of elements in
    // the intersection of two arrays.
    int NumberofElementsInIntersection(int a[], int b[], int n, int m) {
        // Your code goes here
        
        // set<int> st1; int count = 0;
        
        // for(int i=0; i<n; i++){
        //     st1.insert(a[i]);
        // }
        
        // for(int i=0; i<m; i++){
            
        //     if(st1.count(b[i])){
        //         count++;
        //         st1.erase(b[i]);
                
        //     }
        // }
        
        // return count;
        
        int i=0, j=0; int count = 0;
        sort(a, a+n);
        sort(b, b+m);
        while(i<(n) && j<(m)){
            
            if(a[i] == a[i+1] && (i+1) < n){
                i++;
            }
            else if(b[j] == b[j+1] && (j+1) < m){
                j++;
            }
            
            else if(a[i] == b[j]){
                count++;
                i++;
                j++;
            }
            
            else if(a[i] > b[j]){
                j++;
            }
            else if(a[i] < b[j]) { 
                i++;
            }
            
            
        }
        return count;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n], b[m];
        for (int i = 0; i < n; i++) cin >> a[i];

        for (int i = 0; i < m; i++) cin >> b[i];
        Solution ob;
        cout << ob.NumberofElementsInIntersection(a, b, n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends