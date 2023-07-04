//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
      if(N==1){
          return 1;
      }
      
      sort(arr, arr+N);
      int count = 1; int maxi = INT_MIN;
      
      for(int i=0; i<N-1; i++){
          
          if(arr[i] == arr[i+1]){
              continue;
          }
          
          else if(arr[i+1] == arr[i] + 1 ){
              count++;
              maxi = max(maxi, count);
          }
          else{
              count = 1;
          }
      }
      
      if(maxi == INT_MIN){
          return 1;
      }
      
      return maxi;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends