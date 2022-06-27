class Solution {
public:
    int dp[12+1][10001];
    // int helper(int n,vector<int>&coins,int target){
    //     if(target==0 || n==0){
    //         return 0;
    //     }
    //     if(coins[n-1]<=target){
    //         cout<< min(1 + helper(n-1,coins,target-coins[n-1]), helper(n,coins,target) );
    //         return min(1 + helper(n-1,coins,target-coins[n-1]), helper(n,coins,target) );
    //     }
    //     return helper(n-1,coins,target);
    // }
     int helper(int i,vector<int>&coins,int target){
        if(target==0 || i==0){
            return target==0?0:INT_MAX-1;
        }
        if(dp[i][target]!=-1)
            return dp[i][target];
        int res = -1;
         
        if(coins[i-1]<=target){
            int take = 1 + helper(i,coins,target-coins[i-1]);
            int doNotTake = 0 + helper(i-1,coins,target);
            dp[i][target] = res = min(take,doNotTake);
        }
        else
         {
            int doNotTake = helper(i-1,coins,target);
            res = doNotTake;
         }
        return dp[i][target] = res;
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof(dp));
        int res = helper(coins.size(),coins,amount);
       
        
        if(res==INT_MAX-1)
            return -1;
        else
            return res;
        
    }
};