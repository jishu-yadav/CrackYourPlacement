class Solution {
public:
    vector<int> counter(string &s){
        vector<int>count(26,0);
        for(char c:s){
            count[c-'a']++;
        }
        return count;
    }
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
         vector<int> count(26), tmp(26);
        int i;
        for (string b : B) {
            tmp = counter(b);
            for (i = 0; i < 26; ++i)
                count[i] = max(count[i], tmp[i]);
        }
        vector<string> res;
        for (string a : A) {
            tmp = counter(a);
            for (i = 0; i < 26; ++i)
                if (tmp[i] < count[i])
                    break;
            if (i == 26) res.push_back(a);
        }
        return res;
    }
};