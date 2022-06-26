class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int ans=0;
        int n  = nums.size();
        vector<int>dp(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i] > nums[j] && dp[i]<dp[j]+1)
                    dp[i] = dp[j] + 1;
            }
        }
        return *max_element(dp.begin(),dp.end());
        
        // for(int i =0;i<n;i++){
        //     int c=0;
        //     for(int j = i+1;j<n;j++){
        //         if(nums[j]>nums[i]){
        //             c++;
        //             cout<<nums[j]<<" ";
        //         }
        //     }
        //     cout<<"\n";
        //    // cout<<c<<" ";
        //     if(c>ans)
        //         ans = c;
        // }
        // return ans;
        
        
    }
};