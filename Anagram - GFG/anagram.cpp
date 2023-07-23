//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b){
        
        // Your code here
        int len1 = a.length();
        int len2 = b.length();
        
        if(len1 != len2){
            return false;
        }
        
        if(len1 == 1){
            return (a[0] == b[0]);
        }
        
        int count1[26] {0};
        for(int i=0; i< len1; i++){
            count1[a[i]-'a']++;
            count1[b[i]-'a']--;
        }
        
        for(int i=0; i<26; i++){
            
            if(count1[i]){
                return false;
            }
        }
        return true;
        
        
    }

};

//{ Driver Code Starts.

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;
        Solution obj;
        if(obj.isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}

// } Driver Code Ends