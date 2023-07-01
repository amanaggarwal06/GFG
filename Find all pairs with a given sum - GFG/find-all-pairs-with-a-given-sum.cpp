//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
    int findreqnum(int arr[], int n, int target){
        
        int s=0, e= n-1, mid = s+(e-s)/2;
        
        while(s<=e){
            mid = s+(e-s)/2;
            
            if(arr[mid] == target){
                return mid;
            } 
            
            else if(arr[mid] > target){
                e = mid-1;
            }
            
            else {
                s = mid+1;
            }
        }
        
        return -1;
    }
    
    vector<pair<int,int>> allPairs(int A[], int B[], int N, int M, int X)
    {
        // Your code goes here 
        sort(B, B+M);
        vector<pair<int, int>> vec;
        pair<int, int> p;
        
        for(int i=0; i<N; i++){
            
            int reqnum = X - A[i];
            
            int req_num_index = findreqnum(B, M, reqnum);
            
            if(req_num_index > -1){
                
                p.first = A[i];
                p.second  = B[req_num_index];
                vec.push_back(p);
            }
        }
        
    
        sort(vec.begin(), vec.end());
        return vec;
        
    }
    
};


//{ Driver Code Starts.
int main() {
	long long t;
	cin >> t;
	
	while(t--){
	    int N, M, X;
	    cin >> N >> M >> X;
        int A[N], B[M];
        
	    for(int i = 0;i<N;i++)
	        cin >> A[i];
	    for(int i = 0;i<M;i++)
	        cin >> B[i];
	        
	   Solution ob;
	   vector<pair<int,int>> vp = ob.allPairs(A, B, N, M, X);
	   int sz = vp.size();
        if(sz==0)
        cout<<-1<<endl;
        else{
            for(int i=0;i<sz;i++){
                if(i==0)
                cout<<vp[i].first<<" "<<vp[i].second;
                else
                cout<<", "<<vp[i].first<<" "<<vp[i].second;
            }
            cout<<endl;
        }
	}
	return 0;
}
// } Driver Code Ends