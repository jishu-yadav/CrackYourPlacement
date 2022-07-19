class Solution {
public:
    bool isPallin(string &s,int i,int j){
        while(i<j){
            if(s[i++]!=s[j--]){
                return false;
            }
        }
        return true;
    }
    void partitionHelper(int start,string &s,vector<vector<string>>&ans,vector<string>&p){
        if(start>=s.size()) ans.push_back(p);
        for(int end=start;end<s.size();end++){
            // if(isPallin(s.substr(start,end-start+1)))
            if(isPallin(s,start,end))
            {
                p.push_back(s.substr(start,end-start+1));
                partitionHelper(end+1,s,ans,p);
                p.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>p;
        partitionHelper(0,s,ans,p);
        return ans;
    }
};