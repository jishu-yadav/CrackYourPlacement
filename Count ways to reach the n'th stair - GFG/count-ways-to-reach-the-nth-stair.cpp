// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    // TLE using this fib 21 tesct case passed
    // int fib(int n){
    //     if(n==0||n==1)
    //         return n;
    //     return fib(n-1)+fib(n-2);
    // }
    int helper(int n){
        int dp[n+1];
        dp[0]= 1;
        for(int i =1;i<=n;i++){
            int count = 0;
            for(int j=1;j<=2;j++){
                if(j<=i){
                    count+=dp[i-j]%1000000007;
                }
            }
            dp[i] =count;
        }
        return dp[n]%1000000007;
    }
    int countWays(int n)
    {
        // your code here
        
        //return fib(n+1);
        // below code also only 21 tc passed.
        // n = n+1;
        // int dp[n+1];
        if(n<=1)
            return n;
        // dp[0] = 0;
        // dp[1] = 1;
        // for(int i=2;i<=n;i++){
        //     dp[i] = dp[i-1]+dp[i-2];
        // }
        // return dp[n];
        //n=n+1;
        // below also passed only 21 tc
        // int a = 0,b = 1,c=0;
        // for(int i=1;i<n;i++){
        //     c = a+b;
        //     a = b;
        //     b = c;
        // }
        // return c;
        // below code also ran for 21 tcs;
        // int N=n;
        // double phi = (sqrt(5) + 1) / 2;     
        // return round(pow(phi, N) / sqrt(5));
        return helper(n);
    }
};



// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}
  // } Driver Code Ends