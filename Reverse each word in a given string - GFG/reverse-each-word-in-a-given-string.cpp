//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseWords (string s)
    {
        //code here.
        int len = s.length();
        
        if(len==1){
            return s;
        }
        
        int j = 0, i = 0;
        
        while(i< len && j<len){
            
            char ch = s[j];
            if(ch != '.'){
                j++;
            }
            else{
                reverse(s.begin() + i, s.begin() + j);
                i = j+1; j = i;
            }
        }
        
        if(i < len){
            reverse(s.begin() + i, s.end());
        }
        
        return s;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.reverseWords (s) << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends