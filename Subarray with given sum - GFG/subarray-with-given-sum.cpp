//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        // Your code here
        vector<int> ans;
        int start = 0;
        long long sum = arr[0];
        int i=0, j = 0; int start_index = -1, end_index = -1;
        
        while( i<=j && j<n){
            
            while( sum > s){
                // trim krna h
                sum -= arr[i];
                i++;
                start = i;
                
            }
            
            if(  i<=j && sum == s){
                start_index = start;
                end_index = j;
                break;
            }
            
            j++;
            if(j < n){
                sum += arr[j];
            }
        }
        
        if(start_index == -1){
            ans.push_back(-1);
            return ans;
        }
        
        ans.push_back(start_index + 1);
        ans.push_back(end_index + 1);
        return ans;
    }
};

//{ Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends