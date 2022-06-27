class Solution {
public:
    // int f(int idx,int prev_idx,vector<int>nums,int n,vector<vector<int>>&dp){
    //     if(idx==n)
    //         return 0;
    //     if(dp[idx][prev_idx+1]!=-1)
    //         return dp[idx][prev_idx+1];
    //     int len = 0 + f(idx+1,prev_idx,nums,n,dp);//not take case
    //     if(prev_idx==-1 || nums[idx] > nums[prev_idx] ){ //take case
    //         len = max(len, 1 + f(idx+1, idx, nums,n,dp));
    //     }
    //     return dp[idx][prev_idx+1] = len;
    // }
    // int lengthOfLIS(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<vector<int>>dp(n,vector<int>(n+1,-1));
    //     return f(0,-1,nums,n,dp);
    // }
     int lengthOfLIS(vector<int>& nums) {
        int ans = 1;
        int n = nums.size();
        vector<int>dp(n,1);
         for(int i=0;i<n;i++)
         {
             for(int j=0;j<i;j++){
                 if(nums[i]>nums[j]){
                     dp[i] = max(dp[i],dp[j]+1);
                     ans = max(ans,dp[i]);
                 }
             }
         }    
             return ans;
    }
};