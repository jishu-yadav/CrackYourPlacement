class Solution {
public:
    vector<string>ans;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        string op="";
        solve(s,op,wordDict,0);
        return ans;
    }
    void solve(string ip,string &op,vector<string>&mp,int start){
        if(start==ip.size()){
            op.pop_back();
            ans.push_back(op);
            op.push_back(' ');
            return;
        }
        for(int i=start;i<ip.size();i++){
            if(find(mp.begin(),mp.end(),ip.substr(start,i-start+1))!= mp.end() ){
                string prev = op;
                op+= ip.substr(start,i-start+1);
                op.push_back(' ');
                solve(ip,op,mp,i+1);
                op = prev;
            }
        }
        return;
    }
};