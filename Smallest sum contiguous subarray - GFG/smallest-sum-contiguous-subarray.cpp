//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  int smallestSumSubarray(vector<int>& a){
      //Code here
      
      int size = a.size();
      
      if(size == 1){
          return a[0];
      }
      
      long long sum = 0, mini = INT_MAX;
      
      for(int i=0; i<size; i++){
          sum += a[i];
          
          mini = min(mini, sum);
          
          if(sum > 0){
              sum = 0;
          }
      }
      
      return mini;
  }
};


//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        Solution ob;
        
        int ans = ob.smallestSumSubarray(a);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends