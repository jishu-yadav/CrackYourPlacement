class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i=0;i<nums.size();i++)
            sum+=nums[i];
        if(sum%2==0)
            sum/=2;
        else
            return false;
        
        int n = nums.size();
        int dp[n+1][sum+1];
        for(int i=0;i<=n;i++){
            dp[i][0] = 1;
        }
        for(int j=0;j<=sum;j++){
            dp[0][j] = 0;
        }
        dp[0][0] = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(j-nums[i-1] >=0){
                    dp[i][j] =  dp[i-1][j-nums[i-1]] || dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
    }
};