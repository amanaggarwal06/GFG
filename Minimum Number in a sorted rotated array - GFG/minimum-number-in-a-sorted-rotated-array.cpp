//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the minimum element in sorted and rotated array.
    int minNumber(int arr[], int low, int high)
    {
        // Your code here
        int mid = low + (high - low)/2;
        int size =  high - low +1;
        
        while(low<=high){
            int mid_prev = (mid - 1 + size)%size;
            int mid_nxt = (mid + 1)%size;
            if(arr[low] <= arr[high]){
                return arr[low];
            }
            
            else if(mid_nxt < size && mid_prev < size && arr[mid] < arr[mid_nxt] && arr[mid] < arr[mid_prev]){
                return arr[mid];
            }
            
            else if(arr[mid] >= arr[0]){
                low = mid +1;
            }
            else{
                high = mid -1;
            }
            mid = low + (high - low)/2;
            
        }
        return -1;
        
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
		cin>>n;
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];	
		Solution obj;
		cout << obj.minNumber(a,0,n-1) << endl;
	}
	return 0;
}
// } Driver Code Ends