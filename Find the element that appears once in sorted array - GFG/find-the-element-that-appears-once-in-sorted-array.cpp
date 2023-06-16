//{ Driver Code Starts
// Driver code

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
  public:
    int findOnce(int arr[], int n)
    {
        //code here.
        int s =0, e = n-1, mid = s +(e-s)/2;
        int mid_nxt = (mid+1)%n ;
        int mid_prev = (mid-1 + n)%n ;
        
        while(s<=e){
            mid_nxt = (mid+1)%n ;
            mid_prev = (mid-1 + n)%n ;
            if(n == 1){
                return arr[0];
            }
            
            if( arr[mid] != arr[mid_prev] && arr[mid] != arr[mid_nxt]){
                return arr[mid];
            }
            
            else if(arr[mid] == arr[mid_prev]){
                if((mid_prev) % 2 == 0){
                    s = mid +1;
                }
                else{
                    e = mid - 1;
                }
            }
            else if(arr[mid] == arr[mid_nxt]){
                if((mid) % 2 == 0){
                    s = mid +1;
                }
                else{
                    e = mid - 1;
                }
            }
            mid = s +(e-s)/2;
        
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int A[n];
        for(int i = 0;i < n;i++)
        {
            cin>>A[i];
        }
        
        Solution ob;
        
        int res = ob.findOnce(A,n);
        cout << res << endl;
    }
    
    return 0;
}
// } Driver Code Ends