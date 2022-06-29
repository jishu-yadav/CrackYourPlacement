// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    //int dp[1101];
    int help(int i,string s,set<string>&wordDict){
        if(i==s.size())
            return 1;
        string temp;
        for(int j=i;j<s.size();j++){
            temp+=s[j];
            if(wordDict.find(temp)!=wordDict.end()){
                if(help(j+1,s,wordDict))
                    return 1;
            }
        }
        return 0;
    }
    int wordBreak(string A, vector<string> &B) {
        //code here
        set<string>st;
        for(auto &i:B){
            st.insert(i);
        }
        // return help(0,A,st);
        
        
        
        // Another approach using dp tabulation:
        
        //this BELOW APPROACH IS FROM FRAZ YT BUT NOT WORIG PROPRRL 
        int n = A.size();
        vector<int>dp(n+1,0);
        for(int i=1;i<=A.size();i++){
            if(st.find(A.substr(0,i))!=st.end() ){
                dp[i]= 1;
            }
            for(int j=1;j<=i;j++){
                string part2 = A.substr(j,i-j);
                if(st.find(part2)!=st.end()){
                    dp[i] +=dp[j]; 
                }
            }
           
        }
         return dp[A.size()];
         
        // for(int i=n-1;i>=0;i--){
        //     string temp ;
        //     for(int j=i;j<n;j++){
        //         temp+=A[j];
        //         if(st.find(temp)!=st.end()){
        //             dp[i]=dp[j+1];
        //         }
        //     }
        //     dp[i]=0;
        // }
        // return dp[0];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}
  // } Driver Code Ends