//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        int len = x.size();
        
        //edge case
        if(len == 0 || len == 1){
            return false;
        }
        
        stack<char> st;
        for(int i=0; i< len; i++){
            
            char ch = x[i];
            
            if(ch == '(' || ch == '{' || ch == '['){
                st.push(ch);
            }
            
            else{
                //closing bracket
                
                if(!st.empty()){
                    
                    char top = st.top();
                    
                    if( (top == '(' && ch == ')') || (top == '{' && ch == '}') || (top == '[' && ch == ']') ){
                        
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
                else{
                    
                    return false;
                }
            }
        }
        
        if(st.empty()){
            return true;
        }
        
        return false;
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends