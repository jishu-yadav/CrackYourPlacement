class Solution {
public:
    //  bool helper(string s, string p, int i, int j,vector<vector<char>> &mem)
    // {
    //     int sn = s.size();
    //     if(j==p.size()) return i==sn;
    //     if(mem[i][j]!=-1) return mem[i][j];
    //     if(p[j]=='*') {
    //         for(int k=i;k<=sn;k++) if(helper(s,p,k,j+1,mem)) return mem[i][j] = 1;
    //         return mem[i][j] =  0;
    //     }
    //     if(i<sn && (p[j]=='?'||s[i]==p[j])) return mem[i][j] = helper(s,p,i+1,j+1,mem);
    //     return  mem[i][j] = 0;
    // }
    bool isMatch(string s, string p) { 
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int i = 0; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2] || (i && dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
                } else {
                    dp[i][j] = i && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                }
            }
        }
        return dp[m][n];
    }
};