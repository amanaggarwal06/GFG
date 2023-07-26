//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	int countSubstr (string s)
	{
	    // your code here
	    int len = s.length();
	    
	    if(len == 1){
	        return 0;
	    }
	    
	    int count = 0;
	    
	    for(int i=0; i<len; i++){
	        
	        if(s[i] == '1'){
	            count++;
	        }
	    }
	    
	    if(count < 2){
	        return 0;
	    }
	    
	    return (count*(count-1)/2);
	}
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        
        cout << ob.countSubstr (s) << '\n';
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends