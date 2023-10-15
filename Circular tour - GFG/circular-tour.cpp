//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


// } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       //Your code here
       int balance = 0, deficiency = 0; int start = 0;
       vector<bool> visited(n, false);
       
       for(int i=0; (i%n)<n; i++){
           
           i = i%n;
           
           if(visited[i] == false){
               balance += p[i].petrol - p[i].distance;
               visited[i] = true;
           }
           else{
               balance = balance + deficiency;
               if(balance >=0){
                   return start;
               }
               else{
                   return -1;
               }
           }
           
           
           if(balance < 0){
               start = (i+1)%n;
               deficiency += balance;
               balance = 0;
           }
           
       }
       
       return start;
    }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}

// } Driver Code Ends