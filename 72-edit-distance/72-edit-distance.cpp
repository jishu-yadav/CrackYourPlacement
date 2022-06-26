class Solution {
public:
    int dp[1001][1001];
    int minimum(int x,int y,int z){
        return min(x,min(y,z));
    }
    int editDis(string s1,string s2,int m,int n){
        if(m==0)
            return n;
        if(n==0)
            return m;
        if(dp[m][n]!=-1)
            return dp[m][n];
        if(s1[m-1]==s2[n-1])
            return dp[m][n] = editDis(s1,s2,m-1,n-1);
        else
            return 
                dp[m][n] = 1 + minimum(
            editDis(s1,s2,m-1,n-1) , 
            editDis(s1,s2,m-1,n), 
            editDis(s1,s2,m,n-1));
    }
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        
        memset(dp,-1,sizeof(dp));
        dp[m][n] = editDis(word1,word2,m,n);
        return dp[m][n];
    }
};