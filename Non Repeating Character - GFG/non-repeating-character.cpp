//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string S)
    {
       //Your code here
       if(S.length() == 1){
           return S[0];
       }
       
       int arr[26] = {0};
       
       for(int i=0; i< S.length(); i++){
           
           int index = S[i] - 'a';
           arr[index] ++;
       }
       
       for(int i=0; i< S.length(); i++){
           
           int index = S[i] - 'a';
           if(arr[index] == 1){
               return ('a' + index);
           }
       }
       
       return '$';
       
    }

};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--)
	{
	
	    string S;
	    cin >> S;
	    Solution obj;
        char ans = obj.nonrepeatingCharacter(S);
        
        if(ans != '$')
	    cout << ans;
        else cout << "-1";
            
        cout << endl;
	    
	}
	
	return 0;
}

// } Driver Code Ends