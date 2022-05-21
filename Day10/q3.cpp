class Solution {
public:
    int dp[10000+1][12+1];
    int change(vector<int>arr,int w,int n){
        if(w==0 || n==0){
            return w==0?0:INT_MAX-1;
        }
        if(dp[w][n]!=-1){
            return dp[w][n];
        }
        if(arr[n-1]<=w)
            return dp[w][n] = min(change(arr,w,n-1),1 + change(arr,w-arr[n-1],n));
        else
            return dp[w][n] = change(arr,w,n-1);
    }
    int coinChange(vector<int>& coins, int amount) {
        // memset(dp,-1,sizeof(dp));
        // int ans = change(coins,amount,coins.size());
        // return ans==INT_MAX-1?-1:ans;
        
        //or
        
        int n = coins.size();
        
        long long int dp[n+1][amount+1];
        for(int i=0;i<n+1;i++){
            dp[i][0]=0;
        }
        for(int i=0;i<amount+1;i++){
            dp[0][i] = INT_MAX-1;
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<amount+1;j++){
                if(coins[i-1]<=j){
                     dp[i][j] = min (dp[i-1][j] , 1 + dp[i][j-coins[i-1]]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        if(dp[n][amount]<1000000)
            return dp[n][amount];
        return -1;
        
    }
};//coin change
