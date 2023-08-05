//{ Driver Code Starts
//Initial Template for C++

// C program for implementation of Bubble sort
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

// swapping the elements
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}


// } Driver Code Ends
//User function Template for C++

class Solution
{
    
    void BS(int arr[], int n, int round){
        
        //base case
        if(round == n){
            return;
        }
        
        //processing
        for(int i=0; i<n-round; i++){
            
            if(arr[i] > arr[i+1]){
                swap(arr[i], arr[i+1]);
            }
        }
        
        //recursive case
        BS(arr, n, round+1);
    }
    
    public:
    //Function to sort the array using bubble sort algorithm.
    void bubbleSort(int arr[], int n)
    {
        // Your code here 
        BS(arr,  n, 1);
        
    }
};


//{ Driver Code Starts.

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 
// Driver program to test above functions
int main()
{
    int arr[1000],n,T,i;
  
    scanf("%d",&T);
    
    while(T--){
        
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      
    Solution ob;  
      
    ob.bubbleSort(arr, n);
    printArray(arr, n);
    }
    return 0;;
}
// } Driver Code Ends