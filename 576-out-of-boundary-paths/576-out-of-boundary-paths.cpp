class Solution {
public:
    int mod = pow(10,9) + 7;
    //int ans = 0;
    int dfs(int row,int col,int maxMove,int x,int y,int moves,vector<vector<vector<int>>>&dp){
        if(x < 0 || y < 0 ||x>=row || y>=col)
            return 1;
        if(moves==maxMove){
            return 0;
        }
        if(dp[moves][x][y]!=-1)
            return dp[moves][x][y]%mod;
        int tempValue = 0;
        tempValue = (tempValue + dfs(row,col,maxMove,x,y-1,moves+1,dp ))%mod;
        tempValue = (tempValue + dfs(row,col,maxMove,x-1,y,moves+1,dp ))%mod;
        tempValue = (tempValue + dfs(row,col,maxMove,x+1,y,moves+1,dp ))%mod;
        tempValue = (tempValue + dfs(row,col,maxMove,x,y+1,moves+1,dp ))%mod;
        dp[moves][x][y] = tempValue;
        return dp[moves][x][y]%mod;
        
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int moves=0;
        vector<vector<vector<int>>> dp(maxMove + 1, vector<vector<int>> (m + 1, vector<int> (n + 1, -1)));
         // vector<vector<vector<int>>> dp(N + 1, vector<vector<int>> (m + 1, vector<int> (n + 1, -1)));
        // vector<vector<vector<int>>>dp(maxMove+1,vector<vector<int>> (startRow+1 , vector<int>(startColumn+1,-1)) );
        dp[maxMove][m][n] = dfs(m,n,maxMove,startRow,startColumn,0,dp);
        return  dp[maxMove][m][n];
    }
};