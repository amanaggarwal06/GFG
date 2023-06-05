//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool Search(int N, vector<int>& A, int target) {
        // Code here
        int s = 0, e = N-1, mid = s +(e-s)/2;
        
        while(s<=e){
            
            if(A[mid] == target){
                return true;
            }
            
            if(A[mid] == A[s] && A[mid] == A[e]){
                s++;
                e--;
            }
            
            // is my left part sorted?
            else if(A[mid] >= A[s]){
                if(target >= A[s] && target <= A[mid]){
                    e = mid -1;
                }
                else{
                    s = mid +1;
                }
            }
            else{
                if(target >= A[mid] && target <= A[e]){
                    s = mid +1;
                }
                else{
                    e = mid -1;
                }
            }
            mid = s +(e-s)/2;
            
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int key;
        cin >> key;

        Solution obj;
        cout << obj.Search(n, a, key) << "\n";
    }
    return 0;
}
// } Driver Code Ends