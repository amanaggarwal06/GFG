//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int N)
    {
        // your code here
        if(N==1){
            return arr[0];
        }
        
        string ans = "";
        
        sort(arr, arr + N);
        
        string first = arr[0], last = arr[N-1];
        
        for(int i=0; i< min(first.length(), last.length()); i++){
            
            if(first[i] == last[i]){
                ans.push_back(first[i]);
            }
            else{
                break;
            }
        }
        
        if(ans.length() == 0){
            ans = ans + '-' + '1';
            return ans;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends