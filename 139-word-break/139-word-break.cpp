class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>ws(wordDict.begin(),wordDict.end());
        vector<int>memo(s.size(),-1);
        return check(s,ws,0,memo);
    }
    bool check(string s,unordered_set<string>&ws,int start,vector<int>&memo){
        if(start>=s.size()) return true;
        
        if(memo[start]!=-1)
            return memo[start];
        for(int i=start+1;i<=s.size();i++){
            if(ws.count(s.substr(start,i-start)) && check(s,ws,i,memo))
            {
                memo[start]=1;
                return true;
            }
        }
        memo[start]=0;
        return memo[start];
        
    }
};