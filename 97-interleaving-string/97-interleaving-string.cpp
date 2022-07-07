class Solution {
public:
    bool helper(string s1,string s2,string s3,int i,int j,vector<vector<int>>&dp){
        if(s1.length()==i && s2.length()==j ){
            return true;
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(i<s1.length()&&s3[i+j]==s1[i]){
        bool f1 = helper(s1,s2,s3,i+1,j,dp);
        dp[i][j] = f1;
            if(f1){
                return true;
            }
        }
        if(j<s2.length()&&s3[i+j]==s2[j]){
        bool f1 = helper(s1,s2,s3,i,j+1,dp);
            dp[i][j] = f1;
            if(f1){
                return true;
            }
        }
        dp[i][j] = false;
        return false;
      
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length() + s2.length() !=s3.length()){
            return false;
        }
        vector< vector<int>>dp(s1.length()+1, vector<int>(s2.length()+1,-1));
        return helper(s1,s2,s3,0,0,dp);
    }
// TLE will come 
//     bool helper(string s1,string s2,string s3,int i,int j){
//         if(s1.length()==i && s2.length()==j && i+j==s3.length()){
//             return true;
//         }
//         if(i<s1.length()&&s3[i+j]==s1[i]){
//         bool f1 = helper(s1,s2,s3,i+1,j);
//             if(f1){
//                 return true;
//             }
//         }
//         if(j<s2.length()&&s3[i+j]==s2[j]){
//         bool f1 = helper(s1,s2,s3,i,j+1);
//             if(f1){
//                 return true;
//             }
//         }
//         return false;
      
//     }
//     bool isInterleave(string s1, string s2, string s3) {
//         return helper(s1,s2,s3,0,0);
//     }
};