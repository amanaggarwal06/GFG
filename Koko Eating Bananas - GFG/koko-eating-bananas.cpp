//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
    int Valid(int mid, vector<int> piles, int hrs){

        int hrs_cnt = 0;
        for(int i=0; i<piles.size(); i++){

            float value = piles[i];
            hrs_cnt += ceil(value/mid);
        }

        return hrs_cnt;
    }
    
  public:
    int Solve(int N, vector<int>& piles, int h) {
        // Code here
        int size = piles.size();
        int start = 1, end = INT_MIN;
        
        if(size == 1 && h==1){
            return piles[0];
        }
            for(int i=0; i< size; i++){
            end = max(end, piles[i]);
            }
        

        long long ans = end; int mid = start + (end-start)/2;

        while(start <= end ){

            long long hrs_cnt = Valid(mid, piles, h);
            if(hrs_cnt <= h){
                ans =  mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
            mid = start + (end-start)/2;
        }

        return int(ans);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int h;
        cin >> h;
        Solution obj;

        cout << obj.Solve(n, a, h);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends