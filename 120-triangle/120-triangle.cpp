class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[0].size();
        // int dp[n+1];
        // dp[0] = triangle[n-1][0];
        vector<int>dp(triangle.back());
    
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<=i;j++)//moving through the layer and check everynode
                // Find the lesser of its two children, and sum the current value in the triangle with it.
            dp[j] = triangle[i][j]+min(dp[j],dp[j+1]);
//             sum+= min(triangle[i][j],triangle[i][j+1]);
//             cout<< j<<" "<<sum<<" ";
//             cout<< triangle[i][j] << " " <<
//                 triangle<<[i][j+1]<<"\n";
            
//             if(triangle[i][j]<triangle[i][j+1])
//                 j = j+1;
//             cout<< j<<" "<<sum<<" "<< triangle[i][j]<<" "<<triangle<<[i][j+1]<<"\n";
            
        }
        return dp[0];
    }
};