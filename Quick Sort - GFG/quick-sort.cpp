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
        // code here
        //base case
        if(low>= high){
            return;
        }
        
        //processing
        int correct_indx = partition(arr, low, high);
        
        //recursive case
        quickSort(arr, low, correct_indx-1);
        quickSort(arr, correct_indx+1, high);
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
       // Your code here
       if(low == high){
           return high;
       }
       
       int cnt = 0; int pivot_ele = arr[low];
       for(int i= low+1; i<= high; i++){
           if(arr[i] <= pivot_ele){
               cnt++;
           }
       }
       
       int correct_indx = low+cnt;
       swap(arr[low], arr[correct_indx]);
       
       //small ele arr[correct_indx]
       int i = low, j = high;
       while(i<correct_indx && j>correct_indx){
           
           while(arr[i] <= arr[correct_indx]) i++;
           while(arr[j] > arr[correct_indx]) j--;
           
           if(i<correct_indx && j>correct_indx){
               swap(arr[i++], arr[j--]);
           }
           
       }
       
       return (correct_indx);
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