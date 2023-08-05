//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
         // Your code here
         int first = l; 
         int second = m+1;
         int temp[r-l+1]; int indx = 0;
         
         while(first <=m && second<= r){
             
             if(arr[first] <= arr[second]){
                 temp[indx++] = arr[first++];
             }
             else{
                 temp[indx++] = arr[second++];
             }
         }
         
         while(first <= m){
             temp[indx++] = arr[first++];
         }
         while(second <= r){
             temp[indx++] = arr[second++];
         }
         
         for(int i=l; i<=r; i++){
             arr[i] = temp[i-l];
         }
    }
    
    public:
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        
        //base case
        if(l>=r) return;
        
        int mid = l+(r-l)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr,mid+1, r);
        
        //merge two sorted arrays
        merge(arr, l, mid, r);
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends