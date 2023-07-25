//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        //Your code here
        int count = 0; int ans = 0;
        int len = str.length();
        
        int i=0;
        if(str[i] == '-'){
            count++; i++;
        }
        
        for(;i< len; i++){
            char ch = str[i];
            
            if(ch >= '0' && ch <= '9'){
                count++;
            }
            else{
                count = 0;
                break;
            }
        }
        
        if(count != 0){
            // all digits or first one is - and the rest one are digits
            
            stringstream obj;
            obj << str;
            int ans = 0;
            
            obj >> ans;
            return ans;
        }
        
        return -1;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends