//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    
    void solve(int arr[], int indx, vector<int> output, vector<vector<int>> &ans, int Comb_len, int targetSum){
        
        //base case
        if(Comb_len ==0 && targetSum == 0){
            ans.push_back(output);
            return;
        }
        else if(Comb_len == 0) return;
        else if(targetSum == 0) return;
        else if(indx>= 10) return;
        
        //recursive case
        //inclusion
        
        if(targetSum >= arr[indx]){
            output.push_back(arr[indx]);
            
            solve(arr, indx+1, output, ans, Comb_len - 1, targetSum - arr[indx]);
            output.pop_back();
        }
        
        //exclusion
        solve(arr, indx+1, output, ans, Comb_len, targetSum);
    }
    
  public:
    vector<vector<int>> combinationSum(int K, int N) {
        // code here
        vector<vector<int>> ans;
        int arr[10] = {0,1,2,3,4,5,6,7,8,9};
        
        int indx = 1;
        
        vector<int> output;
        
        solve(arr, indx, output, ans, K, N);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K >> N;

        Solution obj;
        vector<vector<int>> ans = obj.combinationSum(K, N);
        sort(ans.begin(), ans.end());
        for (auto &arr : ans) {
            for (auto it : arr) cout << it << ' ';
            cout << endl;
        }
    }
    return 0;
}
// } Driver Code Ends