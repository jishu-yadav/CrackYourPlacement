class Solution {
public:
    int setbits(string s){
        int count=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1')
                count++;
        }
        return count;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        // int ans = 0;
        // int sz = strs.size();
        // for(int i=0;i<sz;i++){
        //     int co = setbits(strs[i]);
        //     int cz = strs[i].size()-co;
        //     if( co<=n && cz<=m ){
        //         ans++;
        //     }
        // }
        // return ans;
        int i,j,k,l,p=strs.size();
        vector<vector<int>> dp(m+1 , vector<int>(n+1));
        
        for(auto &s:strs)
        {
            int x = count(s.begin(),s.end(),'1');
            int y = s.size()-x;
            
            for(i=m;i>=y;i--)
            {
                for(j=n;j>=x;j--)
                {
                    dp[i][j] = max(dp[i][j],1+dp[i-y][j-x]);
                }
            }
        }
        return dp[m][n];
    }
};