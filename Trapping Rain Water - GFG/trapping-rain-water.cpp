//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int height[], int n){
        // code here
        
        int size = n;
        vector<int> max_right(size);
        vector<int> max_left(size);

        max_left[0] = height[0];
        max_right[size-1] = height[size-1];

        for(int i=1; i<size; i++){
            max_left[i] = max( max_left[i-1], height[i] );
        }

        for(int i = size-2; i>=0; i--){

            max_right[i] = max( max_right[i+1], height[i] );
        }

        vector<long long> area(size); long long water_trapped = 0;

        for(int i=0; i<size; i++){
            area[i] = min( max_right[i], max_left[i] ) - height[i];
            water_trapped += area[i];
        }

        return water_trapped;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends