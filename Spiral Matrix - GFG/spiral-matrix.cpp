//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int findK(vector<vector<int>> &a, int n, int m, int k)
    {
        // Your code goes here
        int st_row = 0, end_row = n-1;
        int st_col = 0, end_col = m-1; int count = 0;
        
        while(st_row <= end_row && st_col <= end_col){
        
        for(int i= st_col; i<= end_col; i++){
            count++;
            if(count == k){
                return a[st_row][i];
            }
        }
        st_row++;
        
        for(int i= st_row; st_row <= end_row && st_col <= end_col && i<= end_row; i++){
            count++;
            if(count == k){
                return a[i][end_col];
            }
        }
        end_col--;
        
        for(int i= end_col; st_row <= end_row && st_col <= end_col &&  i>= st_col; i--){
            count++;
            if(count == k){
                return a[end_row][i];
            }
        }
        end_row--;
        
        for(int i=end_row; st_row <= end_row && st_col <= end_col &&  i>= st_row; i--){
            count++;
            if(count == k){
                return a[i][st_col];
            }
        }
        st_col++;
        
        }
        
        return -1;
    }

};

//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        vector<vector<int>> a(n, vector<int>(m, 0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }

        Solution obj;

        cout<< obj.findK(a, n, m, k) << "\n";
        
       
    }
}
// } Driver Code Ends