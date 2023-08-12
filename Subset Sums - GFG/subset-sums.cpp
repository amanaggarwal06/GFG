//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
private: 
    void solve(vector<int> arr, int sum, int indx, int N, vector<int> &ans){
        
        //base case
        if(indx >= N){
            ans.push_back(sum);
            return;
        }
        
        //recursive case
        //exclude
        solve(arr, sum, indx+1, N, ans);
        
        //include
        sum += arr[indx];
        solve(arr, sum, indx+1, N, ans);
        
    }
    
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> ans;
        int sum = 0, indx = 0;
        solve(arr, sum, indx, N,ans);
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends