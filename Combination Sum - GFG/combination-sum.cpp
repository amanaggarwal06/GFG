//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
    
    void solve(vector<int> nums, int indx, vector<int> output, vector<vector<int>> &ans, int target){
        
        while( (indx +1 < nums.size()) && (nums[indx] == nums[indx+1]) ){
            indx++;
        }
        //base case
        if(target==0){
            ans.push_back(output);
            return;
        }
        else if(indx >= nums.size()){
            return;
        }
        
        //recursive case
        
        //inclusion case
        if(nums[indx] <= target){
            output.push_back(nums[indx]);
            solve(nums, indx, output, ans, target - nums[indx]);
            output.pop_back();
        }
        
        //exclusion case
        solve(nums, indx+1, output, ans, target);
    }
    
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        // Your code here
        vector<vector<int> > ans;
        vector<int> output;
        int indx = 0;
        
        sort(A.begin(), A.end());
        solve(A, indx, output, ans, B);
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	
// } Driver Code Ends