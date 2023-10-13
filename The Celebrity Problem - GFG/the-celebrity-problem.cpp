//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        int i = 0, j = n-1;
        
        while(i<j){
            
            if(M[i][j] == 1){
                i++;
            }
            else{
                j--;
            }
        }
        
        int potential_celebrity = j;
        int zero_cnt = 0, ones_cnt = 0;
        
        for(int i=0; i<n; i++){
            
            if(M[potential_celebrity][i] == 0){
                zero_cnt++;
            }
            
            if(M[i][potential_celebrity] == 1){
                ones_cnt++;
            }
        }
        
        if(zero_cnt == n && ones_cnt == (n-1)){
            return potential_celebrity;
        }
        
        return -1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends