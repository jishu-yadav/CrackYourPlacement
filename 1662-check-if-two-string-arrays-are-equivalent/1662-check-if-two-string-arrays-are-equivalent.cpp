class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1 = "",s2="";
        for(int i=0;i<word1.size();i++){
            s1+=word1[i];
        }
        for(int i=0;i<word2.size();i++){
            s2+=word2[i];
        }
        // sort(s1.begin(),s1.end());
        // sort(s2.begin(),s2.end());
        cout<<s1<<" "<<s2<<" ";
        if(s1.size()!=s2.size())
            return false;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i])
                return false;
        }
        return true;
        
    }
};