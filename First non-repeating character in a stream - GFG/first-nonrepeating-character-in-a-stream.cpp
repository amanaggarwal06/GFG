//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    string ans = "";
		    queue<char> q;
		    int count[26] = {0};
		    
		    for(int i=0; i<A.size(); i++){
		        
		        char ch = A[i];
		        count[ch - 'a']++;
		        q.push(ch);
		        
		        if(count[q.front() - 'a'] == 1){
		            ans.push_back(q.front());
		        }
		        else{
		            
		            while(!q.empty() && count[q.front() - 'a'] != 1){
		                q.pop();
		            }
		            
		            if(q.empty()){
		                ans.push_back('#');
		            }
		            else{
		                ans.push_back(q.front());
		            }
		        }
		    }
		    
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends