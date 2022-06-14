class Solution {
public:
    
    // part of tle soln..
    // bool pallin( string s ){
    //     int n = s.size();
    //     int i=0,j=n-1;
    //     while(i<j){
    //         if(s[i++]!=s[j--])
    //             return false;
    //     }
    //     return true;
    // }
   string longestPalindrome(string s){
        int n = s.size();
       if(n==0)
           return "";
       int dp[n][n];
       memset(dp,0,sizeof(dp));
       for(int i=0;i<n;i++){//single char string is always pallin so..
           dp[i][i]=1;
       }
       string ans="";
       ans+=s[0];
        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                // if(s[i-1]==t[i-1]){
                //     dp[i][j] = 1 + dp[i-1][j-1];
                // }else{
                //     dp[i][j] = 0;
                // }
                if(s[i]==s[j])
                if(dp[i+1][j-1]==1 || j-i==1){
                    dp[i][j] = true;
                    if(ans.size()<j-i+1){
                        ans = s.substr(i,j-i+1);
                    }
                }
            }
        }
        return ans;
    }
        
        
    
    // below solution gave tle
//     string longestPalindrome(string s) {
// //         string t = string(s.rbegin(),s.rend());
// //         return longestPalindromeHelper(s,t);
        
        
//         if(s.size()<=1) return s;
        
//         int mx=0;
//         int i=0,j=0;
//         string res = "";
//         for(int i=0;i<s.size()-1;i++){
//               for(int j=1;j<s.size()-i+1;j++){
//                   string str = s.substr(i,j) ;
//                   //cout<<str<<" ";
//                   if(pallin(str)){
//                       //int len = str.size();
//                     if(res.size() < j){
//                         //mx = str.size();
//                         res  = str;
//                     }           
//                   }
//               }
//         }
//         return res;
//     }
};