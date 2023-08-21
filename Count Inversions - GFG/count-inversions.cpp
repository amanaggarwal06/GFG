//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    
    long long merge(long long arr[], long long s, long long mid, long long e){
        
        //two sorted array s, mid; mid+1, e
        long long cnt = 0; vector<long long> temp;
        long long i = s, j = mid+1;
        while( (i<= mid) && (j<=e) ){
            if(arr[i] <= arr[j]){
                temp.push_back(arr[i]);
                i++;
            }
            else{
                temp.push_back(arr[j]);
                cnt += (mid-i+1);
                j++;
            }
        }
        while(i<=mid){
            temp.push_back(arr[i++]);
        }
        while(j<=e){
            temp.push_back(arr[j++]);
        }
        
        for(int i=0; i<temp.size(); i++){
            arr[s++] = temp[i];
        }
        return cnt;
        
    }
    
    long long mergeSort(long long arr[], long long s, long long e){
        
        long long mid = s+(e-s)/2; long long cnt = 0;
        
        //base case
        if(s>=e){
            return 0;
        }
        
        cnt += mergeSort(arr, s, mid); //left
        cnt += mergeSort(arr, mid+1, e); //right
        
        cnt += merge(arr, s, mid, e);
        return cnt;
    }
    
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        return mergeSort(arr, 0, N-1);
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends