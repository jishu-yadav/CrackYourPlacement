class Solution {
public:
    bool isAnagram(string s, string t) {
        // sort(s.begin(),s.end());
        // sort(t.begin(),t.end());
        // return s==t;
        vector<int>hash(26,0);
        for(int i=0;i<s.size();i++){
            hash[s[i]-'a']++;
        }
        for(int i=0;i<t.size();i++){
            hash[t[i]-'a']--;
        }
        for(int i=0;i<hash.size();i++){
            if(hash[i]!=0){
                return false;
            }
        }
        return true;
    }
};