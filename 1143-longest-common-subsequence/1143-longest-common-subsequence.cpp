class Solution {
public:
    int dp[1001][1001];
    int helper(string s1, int n,string s2, int m){
        if(m== 0 || n==0)
            return 0;
        if(dp[m][n]!=-1)
            return dp[m][n];
        
        if(s1[m-1]==s2[n-1])
            return dp[m][n] = 1+helper(s1,m-1,s2,n-1);
        else{
            return dp[m][n] = max(helper(s1,m,s2,n-1) , helper(s1,m-1,s2,n));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp,-1,sizeof(dp));
        int n = text1.size();
        int m = text2.size();
       // helper(text1,text1.size(),text2,text2.size());
        for(int i=0;i<=n;i++){
            dp[i][0] = 0;
        }
        for(int j=0;j<=m;j++){
            dp[0][j] = 0;
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1])
                    dp[i][j] = 1+dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};