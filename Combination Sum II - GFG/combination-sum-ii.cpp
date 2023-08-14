//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    
    void solve(vector<int> nums,int indx,vector<int> output,vector<vector<int>> &ans,int target){
        
        if(target == 0){
            ans.push_back(output);
            return;
        }
        
        for(int i= indx; i< nums.size(); i++){
            
            if(i != indx && nums[i] == nums[i-1] ){
                continue;
            }
            
            //include
            if(target >= nums[i]){
                output.push_back(nums[i]);
                solve(nums, i+1, output, ans,target - nums[i]);
                output.pop_back();
            }
            else{
                break;
            }
        }
    }
    
  public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        // Write your code here
        vector<vector<int>> ans;
        vector<int> output;
        
        int indx = 0;
        sort(candidates.begin(), candidates.end());
        solve(candidates, indx, output, ans, target);
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {

    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> candidates(n);
        for (int i = 0; i < n; ++i) {
            cin >> candidates[i];
        }
        // char marker;
        // cin >> marker;

        Solution obj;

        vector<vector<int>> comb = obj.combinationSum2(candidates, k);
        sort(comb.begin(), comb.end());
        cout << "[ ";
        for (int i = 0; i < comb.size(); i++) {
            cout << "[ ";
            for (int j = 0; j < comb[i].size(); j++) {
                cout << comb[i][j] << " ";
            }
            cout << "]";
        }
        cout << " ]\n";

        // cout << "\n~\n";
    }
    fclose(stdout);
    return 0;
}

// } Driver Code Ends