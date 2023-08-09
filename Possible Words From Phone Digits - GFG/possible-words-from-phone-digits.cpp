//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{   
    void solve(int a[], int N, string output, string mapping[], int indx, vector<string> &ans){
        
        //base case
        if(indx >= N){
            ans.push_back(output);
            return;
        }
        
        //processing
        int element = a[indx];
        string value = mapping[element];
        
        //recursive case
        for(int i=0; i< value.length(); i++){
            
            output.push_back(value[i]);
            solve(a, N, output, mapping, indx+1, ans);
            output.pop_back();
        }
    }
    
    public:
    //Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int N)
    {
        //Your code here
        vector<string> ans;
        string output = "";
        
        string mapping[10] = {"", "", "abc" , "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        solve(a, N, output, mapping, 0, ans);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}
// } Driver Code Ends