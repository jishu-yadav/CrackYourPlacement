class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
         int maxL  = INT_MIN;
        vector<vector<int>>dp(nums1.size()+1, vector<int>(nums2.size()+1));
        for(int i=1;i<=nums1.size();i++){
            for(int j =1;j<=nums2.size();j++){
                if(nums1[i-1]==nums2[j-1])
                    dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
                    maxL = max(maxL, dp[i][j]);
                
            }
        }
        return maxL;
    }
};