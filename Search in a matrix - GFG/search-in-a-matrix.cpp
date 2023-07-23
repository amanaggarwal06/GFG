//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int matSearch (vector <vector <int>> &mat, int N, int M, int X)
	{
	    // your code here
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

int main ()
{
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        vector <vector <int>> arr (n, vector <int> (m));
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                cin >> arr[i][j];
                
        int x; cin >> x;
        Solution ob;
        cout << ob.matSearch (arr, n, m, x) << endl;
    }
}
// } Driver Code Ends