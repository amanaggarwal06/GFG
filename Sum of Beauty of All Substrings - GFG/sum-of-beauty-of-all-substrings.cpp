//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int beautySum(string s) {
        // Your code goes here
        
        int len = s.length(); int beauty = 0;
        if(len == 1){
            return 0;
        }
        

        for(int i=0; i<len; i++){

            int hp[26] {0}; 
            hp[s[i] - 'a']++;

            for(int j=i+1; j<len; j++){
                
                int maxi = INT_MIN, mini = INT_MAX;
                hp[s[j] - 'a']++;

                for(int k=0; k<26; k++){
                    if(hp[k]) {
                        maxi = max(maxi, hp[k]);
                        mini = min(mini, hp[k]);
                        }
                }
                // cout<< "Maxi = "<< maxi<< endl << "Mini = "<< mini<< endl;
                beauty += (maxi - mini);


            }
        }
        // cout<< "Beauty = "<< beauty << endl;
        return beauty;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.beautySum(s) << endl;
    }
    return 0;
}
// } Driver Code Ends