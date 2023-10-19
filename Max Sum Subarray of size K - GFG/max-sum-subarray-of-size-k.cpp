//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        // code here 
        
        long long ans = 0;
        long long maxi = INT_MIN;
        queue<long> q;
        
        for(int i=0; i<K; i++){
            q.push(Arr[i]);
            ans += Arr[i];
        }
        
        maxi = max(maxi, ans);
        
        for(int i=K; i<N; i++){
            
            //removing element
            ans = ans - q.front();
            q.pop();
            
            //adding new element
            ans = ans + Arr[i];
            q.push(Arr[i]);
            
            maxi = max(maxi, ans);
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
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends