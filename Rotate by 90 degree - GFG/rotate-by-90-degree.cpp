//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution
{   
    public:
    //Function to rotate matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int> >& matrix, int n) 
    { 
        // code here 
        if(n==1){
            return;
        }
        
        for(int i=0; i<n; i++){
            for(int j=i ; j<n; j++){
                
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        // transpose of the matrix done--
        
        for(int col=0; col<n; col++){
            int strow = 0, endrow = n-1;
            
            while(strow< endrow){
                swap(matrix[strow][col], matrix[endrow][col]);
                strow++; endrow--;
            }
        }
        // rotatrion of matix by 90 is done.
    } 
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(n, 0);
            for( int j=0; j<n; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        ob.rotateby90(matrix, n);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends