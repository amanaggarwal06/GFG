//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    
    vector< int> Nsl( long long heights[], int n){

        stack < pair<int, int> > st; int pseudo_index = -1;
        vector<int> v;

        for(int i=0; i< n; i++){

            if(st.empty()){
                v.push_back(pseudo_index);
            }
            else{

                if(st.top().first < heights[i]){
                    v.push_back(st.top().second);
                }
                else{

                    while(!st.empty() && st.top().first >= heights[i]){
                        st.pop();
                    }

                    if(st.empty()){
                        v.push_back(pseudo_index);
                    }
                    else{
                        v.push_back(st.top().second);
                    }
                }
            }
            st.push( {heights[i], i} );
        }
        
        return v;
    }

    vector<int>Nsr(long long heights[], int n){

        stack < pair<int, int> > st; 
        int pseudo_index = n;
        vector<int> v;

        for(int i=n-1 ; i>=0 ; i--){

            if(st.empty()){
                v.push_back(pseudo_index);
            }
            else{

                if(st.top().first < heights[i]){
                    v.push_back(st.top().second);
                }
                else{

                    while(!st.empty() && st.top().first >= heights[i]){
                        st.pop();
                    }

                    if(st.empty()){
                        v.push_back(pseudo_index);
                    }
                    else{
                        v.push_back(st.top().second);
                    }
                }
            }
            st.push( {heights[i], i} );
        }
        reverse(v.begin(), v.end());
        return v;
    }
    
    long long getMaxArea(long long heights[], int n)
    {
        // Your code here
        vector<int> left;
        left = Nsl(heights, n);
        vector<int> right;
        right = Nsr(heights, n);

        vector<int> width; vector<long long> area;
        long long maxi = INT_MIN;

        for(int i=0; i< n; i++){

            width.push_back(right[i] - left[i] - 1 );
            area.push_back (width[i]*heights[i] );
        }
        
        for(int i=0; i<area.size(); i++){
            maxi = max(maxi, area[i]);
        }

        return maxi;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends