//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:

bool isValid(vector<int> & stalls, int n, int k, int mid){
    sort(stalls.begin(), stalls.end());
    int cowCount = 1;
    int cowPos = stalls[0];
    
    for(int i=0; i< stalls.size(); i++){
        
        if(stalls[i] - cowPos >= mid){
            cowCount++;
            
            if(cowCount == k){
                return true;
            }
            cowPos = stalls[i];
        }
    }
    return false;
    
    
    
}

    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        if(k>n){
            return -1;
        }
        
        int s =0; int res = INT_MIN;
        for(int i=0; i<stalls.size(); i++){
            res = max(stalls[i], res);
        }
        
        int e = res; int ans = -1;
        int mid = s +(e-s)/2;
        
        while(s<=e){
            
            if(isValid(stalls, n, k, mid)){
                ans = mid;
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
            mid = s +(e-s)/2;
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