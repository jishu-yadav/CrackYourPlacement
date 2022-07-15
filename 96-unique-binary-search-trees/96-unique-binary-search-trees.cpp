class Solution {
public:
    int cat(int n){
        int dp[n+1];
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2;i<=n;i++){
            dp[i]= 0;
            for(int j=0;j<i;j++){
                dp[i] += dp[j]*dp[i-j-1];
            }
        }
        return dp[n];
    }
    int numTrees(int n) {
       return cat(n);
       
        // int result = 0;
        // if(n==1|| n==0)
        //     return 1;
        // for(int i=0;i<n;i++){
        //     result+=numTrees(i)*numTrees(n-i-1);
        // }
        // return result;
    }
};