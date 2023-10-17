//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *nums, int n, int k)
    {
        // your code here
        vector<int> ans;
        deque< int> dq;
        int size = n;

        //edge cases
        if(size < k){
            return ans;
        }
        else if(size == k){

            int maxi = INT_MIN;
            for(int i=0; i<size; i++){

                maxi = max(maxi, nums[i]);
            }

            ans.push_back(maxi);
            return ans;
        }

        //window filling
        for(int i=0; i<k; i++){

            while( !dq.empty() && nums[i] > nums[dq.back()]){
                dq.pop_back();
            }

            dq.push_back(i);
        }

        ans.push_back( nums[dq.front() ]);

        //traversing rest of the array
        for(int i=k; i<size; i++){

            //removing out of bound elements
            if(i - dq.front() >= k){
                dq.pop_front();
            } 

            while( !dq.empty() && nums[i] > nums[dq.back()]){
                dq.pop_back();
            }

            dq.push_back(i);

            ans.push_back( nums[dq.front()] );

        }

        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends