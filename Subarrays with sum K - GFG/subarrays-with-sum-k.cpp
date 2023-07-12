//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int findSubArraySum(int Arr[], int N, int k)
    {
        // code here
        // +, -, zeroes so hashing will be used
        
        map<long long, int> hashmap;
        long long sum = 0; int count = 0;
        
        for(int i=0; i<N; i++){
            sum += Arr[i];
            
            if(sum == k){
                count++;
            }
            
            long long rem_sum = sum - k;
            
            if(hashmap.find(rem_sum) != hashmap.end()){
                count += hashmap[rem_sum];
            }
                
                hashmap[sum] ++ ;
            
        }
        
        return count;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int Arr[N];
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.findSubArraySum(Arr, N, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends