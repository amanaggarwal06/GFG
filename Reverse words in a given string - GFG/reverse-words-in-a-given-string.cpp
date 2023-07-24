//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string s) 
    { 
        // code here 
        string ans = "";
        int len = s.length(); int i = len-1; int start = len-1;
        int wordcount = 0;
        
        if(len==1){
            return s;
        }
        
        while(i>=0){
            if(s[i] != '.'){
                i--;
                continue;
            }
            if(wordcount){
                ans.push_back('.');
            }
            
            ans = ans + s.substr(i+1, start-i);
            wordcount++;
            start = i-1; i--;
        }
        
        if(wordcount){
            ans.push_back('.');
        }
        ans = ans  +  s.substr(0, start+1);
        return ans;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends