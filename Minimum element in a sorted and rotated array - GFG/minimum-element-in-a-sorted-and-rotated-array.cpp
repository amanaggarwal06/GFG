//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int findMin(int arr[], int n){
        //complete the function here
        
        int s=0, e = n-1, mid  = s+ (e-s)/2;
        
        while(s<e){
            if(arr[s] < arr[e]){
                return arr[s];
            }
            
            else if(arr[mid] >= arr[s]){
                s = mid + 1;
            }
            else {
                e = mid;
            }
            mid  = s+ (e-s)/2;
            
        }
    return arr[s];
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
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution ob;
		cout<<ob.findMin(a, n)<<endl;
	}
	return 0;
}
// } Driver Code Ends