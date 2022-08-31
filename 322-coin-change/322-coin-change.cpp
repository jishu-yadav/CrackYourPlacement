class Solution {
public:
    int dp[12+1][10000+1];
    int helper(int i, vector<int>&coins,int target){
        if(i==0 || target==0)
            return target==0?0:INT_MAX-1; 
        if(dp[i][target]!=-1)
            return dp[i][target];
        int res = -1;
        if(coins[i-1]<=target){
            int take = 1+helper(i,coins,target-coins[i-1]);
            int notTake =0+ helper(i-1,coins,target);
            dp[i][target] = res = min(take, notTake);
        }else{
             int notTake = helper(i-1,coins,target);
             res  = notTake;
        }
        return dp[i][target] = res;
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        memset(dp,-1,sizeof(dp));
        int res = helper(n,coins,amount);
        if(res==INT_MAX-1)
            return -1;
        else
            return res;
    }
};