class Solution {
public:
    int lcs(string s,string t){
       int m = s.size(), n =t.size();
       if(n==0 && m==0)
           return 0;
       int dp[m+1][n+1];
      
        
       for(int i=0;i<=m;i++){
           dp[i][0] = 0;
       }
       for(int i=0;i<=n;i++){
           dp[0][i] = 0;
       }
        int ans=0;
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
              
            }
        }
        return dp[m][n];
    }
    int minDistance(string word1, string word2) {
        int n = lcs(word1,word2);
        cout<< n<<" ";
        return word1.size() - n + word2.size()-n;
    }
};