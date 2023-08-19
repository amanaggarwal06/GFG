//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
    bool possible(long long days,vector<int> bloomDay, int m, int k){
        
        int count = 0, num = 0;

        for(int i=0; i< bloomDay.size(); i++){

            if(bloomDay[i] <= days){
                count++;
            }
            else{
                num += count/k;
                count = 0;
            }
        }

        num += count/k;

        if(num < m) return false;
        return true;
    }
    
  public:
    int solve(int m, int k, vector<int> &bloomDay){
      // Code here
      
      int size = bloomDay.size();
        long long no_of_flowers = m;
        no_of_flowers = no_of_flowers*k;

        if(size < no_of_flowers){
            return -1;
        }

        //search space
        int s = INT_MAX, e = INT_MIN; 

        for(int i=0; i< bloomDay.size(); i++){

            e = max(e, bloomDay[i]);
            s = min(s, bloomDay[i]);
        }
        long long mid = s + (e-s)/2; long long ans = e;

        //binary search
        while(s <= e){

            if( possible(mid, bloomDay, m, k)){
                ans = mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }

            mid = s + (e-s)/ 2;
        }

        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, k;
    cin >> m >> k;
    string s;
    getline(cin, s);
    getline(cin, s);
    int n = s.length();
    int num = 0;
    bool f = 0;
    vector<int> bloomDay;
    for (int i = 0; i < n; i++)
    {
      if (s[i] == ' ')
      {
        if (!f)
          continue;
        bloomDay.push_back(num);
        num = 0;
        f = 0;
      }
      else
      {
        num = (num * 10) + (s[i] - '0');
        f = 1;
      }
    }
    if (f)
    {
      bloomDay.push_back(num);
    }
    Solution obj;
    cout<<obj.solve(m, k, bloomDay)<<endl;
    }
    return 0;
}
// } Driver Code Ends