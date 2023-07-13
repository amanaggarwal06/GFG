//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        
        int k= 0;
        int maxi = INT_MIN, length = 0;
        long long sum = 0;
        
        map<long long, int> hashmap;
        
        for(int i=0; i<n; i++){
            
            sum += A[i];
            
            if(sum == k){
                maxi = max(maxi, i+1);
            }
            
            long long rem = sum - k;
            
            if(hashmap.find(rem) != hashmap.end()){
                int value = hashmap[rem];
                
                maxi = max(maxi, (i - value));
            }
            
            if(hashmap.find(sum) == hashmap.end()){
                hashmap[sum] = i;
            }
        }
        
        if(maxi == INT_MIN){
            return 0;
        }
        
        return maxi;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends