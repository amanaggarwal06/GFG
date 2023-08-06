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
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        // code 
        //base case
        if(low>= high){
            return;
        }
        
        int index = partition(arr, low, high);
        
        //recursive case
        quickSort(arr, low, index-1);
        quickSort(arr, index+1, high);
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
       // Your code here
       int pivotEle = arr[low]; int cnt = 0;
       
       for(int i= low+1; i<= high; i++){
           if(arr[i] <= pivotEle){
               cnt++;
           }
       }
       
       int pivotIndex = low + cnt;
       swap(arr[low], arr[pivotIndex]);
       
       // left smaller elements than pivot
       //right larger element than pivot
       
       int i = low, j = high;
       while(i< pivotIndex && j> pivotIndex){
           
           while(arr[i] <= pivotEle) i++;
           while(arr[j] > pivotEle) j--;
           
           if(i< pivotIndex && j> pivotIndex){
               swap(arr[i++], arr[j--]);
           }
       }
       
       return pivotIndex;
    }
};


//{ Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends