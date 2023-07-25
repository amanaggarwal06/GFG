//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &str) {
        // code here
        unordered_map<char, int> hp =  {
            
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000} };
        
        int ans = 0; int len = str.length();
        
        if(len == 1){
            return hp[str[0]];
        }
        
        int i=0;
        for(; i<len-1; i++){
            
            int value1 = hp[str[i]];
            int value2 = hp[str[i+1]];
            
            if(value1 >= value2){
                ans += value1;
            }
            
            else {
                ans  = ans - value1 + value2;
                i++;
            }
        }
        
        if(i== len-1){
            ans += hp[str[i]];
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends