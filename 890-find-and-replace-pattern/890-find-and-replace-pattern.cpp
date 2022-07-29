class Solution {
public:
    bool check(string s, string t){
         map<char,char>mp;
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])!=mp.end()){
                if(mp[s[i]]!=t[i])
                    return false;
            }
            else
                mp[s[i]]=t[i];
        }
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>result;
        for(auto word:words){
            if(check(word,pattern) && check(pattern,word)){
                result.push_back(word);
            }
        }
        return result;
    }
};