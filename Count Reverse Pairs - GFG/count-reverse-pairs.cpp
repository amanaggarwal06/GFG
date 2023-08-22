//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
    
    void merge(vector<int> &arr, int s, int mid, int e){
        
        vector<int> temp;
        int i = s, j = mid+1;
        
        while(i<= mid && j<= e){
            if(arr[i] <= arr[j]){
                temp.push_back(arr[i++]);
            }
            else{
                temp.push_back(arr[j++]);
            }
        }
        
        while(i<=mid){
            temp.push_back(arr[i++]);
        }
        while(j<= e){
            temp.push_back(arr[j++]);
        }
        
        for(int i = s; i<= e; i++){
            arr[i] = temp[i-s];
        }
    }
    
     int CountPairs(vector<int> &arr, int s, int mid, int e){

      int cnt = 0, right = mid+1;

      for(int i= s; i<= mid; i++){

          long long comparingNo = 2*arr[right];
          while(right <= e && arr[i] > comparingNo){
              right++;
              comparingNo = arr[right]; comparingNo = 2*comparingNo;
          }
          cnt = cnt + right - (mid+1);
      }
      return cnt;
  }
    
    int mergeSort(vector<int> &arr, int s, int e){
        
        //base case
        if(s>=e){
            return 0;
        }
        
        //processing
        int cnt = 0;
        int mid = s+(e-s)/2;
        
        //recursive calls
        cnt += mergeSort(arr, s, mid);
        cnt += mergeSort(arr, mid+1, e);
        
        cnt += CountPairs(arr, s, mid, e);
        merge(arr, s, mid, e);
        
        return cnt;
    }
    
  public:
    int countRevPairs(int n, vector<int> arr) {
        // Code here
        
        return mergeSort(arr, 0, arr.size()-1);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countRevPairs(n, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends