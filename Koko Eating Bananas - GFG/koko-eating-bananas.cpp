//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    bool isValid(vector<int>& piles, int H, int mid){
        
        int NOhours = 0;
        for(int i=0; i< piles.size(); i++){
            NOhours += ceil( double(piles[i]) / mid);
        }
        
        if(NOhours > H) return false;
        return true;
    }
    
  public:
    int Solve(int N, vector<int>& piles, int H) {
        // Code here
        int s = 0, e = *max_element(piles.begin(), piles.end());
        
        int mid = s+(e-s)/2, ans = 0;
        
        while(s<=e){
            
            if(isValid(piles, H, mid)){
                ans = mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }
            mid = s+(e-s)/2;
        }
        
        return ans;
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
        int h;
        cin >> h;
        Solution obj;

        cout << obj.Solve(n, a, h);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends