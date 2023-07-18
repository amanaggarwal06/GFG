//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {
        // Your code here
        int length  = str.length(); 
        int arr[26] {0}; 
        
        for(int i=0; i< length; i++){
            
            int num = str[i] - 'a';
            arr[num]++;
            
        }
        int  maxi = arr[0]; int ans = 0;
        
        for(int i=1; i<26; i++){
            
            if(arr[i] > maxi){
                maxi = arr[i];
                ans = i;
            }
        }
        
        for(int i=0; i<26; i++){
            
            if(arr[i] == maxi){
                ans = i;
                break;
            }
        }
        
        return (ans + 'a');
        
    }

};

//{ Driver Code Starts.

int main()
{
   
    int t;
    cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
    	Solution obj;
        cout<< obj.getMaxOccuringChar(str)<<endl;
    }
}
// } Driver Code Ends