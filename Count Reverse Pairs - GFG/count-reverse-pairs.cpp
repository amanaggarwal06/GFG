//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
  void merge( vector<int> &arr, int low, int mid, int high){
      
      int first = low, second = mid+1;
      vector<int> temp;
      
      while(first <= mid && second <= high){
          
          if(arr[first] <= arr[second]){
              temp.push_back(arr[first++]);
          }
          else{ // first > second
              temp.push_back(arr[second++]);
          }
      }
      
      while(first <= mid){
          temp.push_back(arr[first++]);
      }
      
      while(second <= high){
          temp.push_back(arr[second++]);
      }
      
      //putting sorted elements in the given array
      for(int i=low; i<= high; i++){
          arr[i] = temp[i-low];
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
    
    int cnt = 0;
    //base case
    if(s>=e){
        return cnt;
    }
    
    int mid = s+(e-s)/2;
    
    //recursive case
    cnt += mergeSort(arr, s, mid);
    cnt += mergeSort(arr, mid+1, e);
    
    cnt += CountPairs(arr, s, mid, e);
    merge(arr, s, mid, e);
    
    return cnt;
    
  }
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