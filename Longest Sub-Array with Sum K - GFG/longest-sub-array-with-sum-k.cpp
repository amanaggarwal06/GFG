//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function
        
        long long sum = 0;
        int max_length = INT_MIN;
        
        map<long long, int> hashmap;
        
        for(int i=0; i<N; i++){
            sum += A[i];
            
            if(sum == K){
                int length = i+1;
                max_length = max(max_length, length);
            }
            
            long long rem = sum - K;
            
            if(hashmap.find(rem) != hashmap.end()){
                max_length = max(max_length, (i- hashmap[rem]));
            }
            
            if(hashmap.find(sum) == hashmap.end()){
                hashmap[sum] = i;
            }
            
        }
        
        if(max_length == INT_MIN){
            return 0;
        }
        
        return max_length;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends