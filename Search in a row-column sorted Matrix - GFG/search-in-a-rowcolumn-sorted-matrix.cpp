//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to search a given number in row-column sorted matrix.
    bool search(vector<vector<int> > mat, int N, int M, int X) 
    {
        // code here 
        int total = N*M;
	    
	    if(total == 1){
	        return (mat[0][0] == X);
	    }
	    
	    int start_row = 0, end_row = N-1;
	    int start_col = 0, end_col = M-1;
	    
	    while(start_row <= end_row && end_col >= start_col){
	        
	        int element = mat[start_row][end_col];
	        
	        if(element == X){
	            return 1;
	        }
	        else if(element > X){
	            end_col--;
	        }
	        else{
	            start_row++;
	        }
	    }
	    
	    return 0;
    }
};

//{ Driver Code Starts.
int main() 
{ 
	int t;
    cin>>t;
    while(t--)
    {

 		int n, m;
    	cin>> n>> m;
        vector<vector<int> > matrix(n);
            
        for(int i=0; i<n; i++)
        {
            matrix[i].assign(m, 0);
            for( int j=0; j<m; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        int x;
        cin>>x;
        Solution obj;
        if (obj.search(matrix,n,m,x)) 
            cout << "1\n"; 
        else
            cout << "0\n"; 
    }
	return 0; 
} 


// } Driver Code Ends