// { Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
   
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    // {
    //     map<int,int>mp;
    //     for(int i=0;i<n;i++){
    //         mp[dep[i]]=arr[i];
    //     }
    //     int p = 1;
    //     for(int i=1;i<n;i++){
    //         if(mp[dep[i]]<=dep[i-1]){
    //             p++;
    //         }
            
    //         //else{
    //         //     continue;
    //         // }
    //     }  
    sort(arr,arr+n);
    sort(dep,dep+n);
    int j=0,i=1;
    int ans=1;
    int count=1;
    while(i<n&&j<n){
        if(arr[i]<=dep[j]){//one more platform req
            count++;
            i++;
        }else{//
            count--;
            j++;
        }
        ans = max(ans,count);
    }
      
      return ans;
    	// Your code here
    }
};


// { Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}  // } Driver Code Ends// minimum number of platforms needed 
