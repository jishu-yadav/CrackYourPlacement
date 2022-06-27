class Solution {
public:
    //int dp[101][101];
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
      //  vector<vector<int>>dp(n,vector<int>(m,0));
//         for(int i=1;i<m;i++){
//             dp[0][i] = dp[0][i-1]+grid[0][i];
//         }
//         for(int i=1;i<n;i++){
//             dp[i][0] = dp[i-1][0]+grid[i][0];
//         }
        
//         for(int i=1;i<n;i++){
//             for(int j=1;j<m;j++){
//                 dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
//             }
//         }   
        
        for(int i=1;i<m;i++){
            grid[0][i] = grid[0][i-1]+grid[0][i];
        }
        for(int i=1;i<n;i++){
            grid[i][0] = grid[i-1][0]+grid[i][0];
        }
        
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                grid[i][j] = min(grid[i-1][j]+grid[i][j] , grid[i][j-1]+grid[i][j] );
           }
        }   
        
        return grid[n-1][m-1];
        
    }
};