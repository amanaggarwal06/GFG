//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:

    bool issPossible(vector<int> stalls, int n, int k, int mid){
        
        int cowCount = 1;
        int starting_pos = stalls[0];
        
        for(int i=0; i<n; i++){
            
            if(stalls[i] - starting_pos >= mid){
                
                cowCount ++ ;
                if(cowCount == k){
                    return true;
                }
                else{
                    starting_pos = stalls[i];
                }
                
            }
            
        }
        return false;
      
    }
    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        if(n < k){
            return -1;
        }
        
        sort(stalls.begin(), stalls.end());
        int s = 0;
        int maxi = INT_MIN;
        for(int i=0; i<n; i++){
            maxi = max(maxi, stalls[i]);
        }
        
        int e = maxi;
        int mid = s + (e-s)/2; int ans= -1;
        
        while(s<=e){
            
            if(issPossible(stalls, n , k, mid)){
                
                ans = mid;
                s = mid +1;
            }
            
            else{
                e = mid -1;
            }
            mid = s + (e-s)/2;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends