//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    
    bool isspossible(int arr[], int N, int M, int mid){
        
        int studentcount = 1;
        int pagecount = 0;
        
        for(int i=0; i<N; i++){
            if(pagecount + arr[i] <= mid){
                pagecount += arr[i];
                    }
            
            else{
                studentcount++;
                if(studentcount > M || arr[i] > mid){
                    return false;
                }
                else{
                    pagecount = 0;
                    pagecount = arr[i];
                }
            }
        }
        // if(studentcount < M){
        //     return false;
        // }
        return true;
        
        
    }
    
    // int checking(int arr[], int N, int M, int ans){
        
    //     int studentcount = 1;
    //     int pagecount = 0;
        
    //     for(int i=0; i<N; i++){
    //         if(pagecount + arr[i] <= ans){
    //             pagecount += arr[i];
    //                 }
            
    //         else{
    //             studentcount++;
    //             if(studentcount > M || arr[i] > ans){
    //                 return -1;
    //             }
    //             else{
    //                 pagecount = 0;
    //                 pagecount = arr[i];
    //             }
    //         }
    //     }
    //     if(studentcount < M){
    //         return -1;
    //     }
    //     return ans;
        
        
        
    // }
    int findPages(int A[], int N, int M) 
    {
        //code here
        int s = 0;
        if(N< M){
            return -1;
        }
       
        int sum = 0; int ans = -1;
        for(int i=0; i<N; i++){
            sum += A[i];
        }
        
        int e = sum;
        int mid = s + (e-s)/2;
        
        while(s<=e){
            
            if(isspossible(A, N, M, mid)){
                ans = mid;
                e = mid -1;
            }
            
            else{
                s = mid + 1;
            }
            mid = s + (e-s)/2;
            
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends