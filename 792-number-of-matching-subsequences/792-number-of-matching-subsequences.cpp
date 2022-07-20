class Solution {
public:
    bool isSubsequence(string &a,string b){
        int i=0,j=0;
        int m = a.size();
        int n = b.size();
        while(i<m && j<n){
            if(a[i]==b[j]){
                i++;
                j++;
            }else{
                i++;
            }
        }
        return (j==n);
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        int c = 0;
        unordered_map<string,int>mp;
        for(int i=0;i<words.size();i++){
            mp[words[i]]++;
        }
        for(auto it = mp.begin();it!=mp.end();it++){
            if(isSubsequence(s,it->first)){
                c += it->second;
            }
        }
        return c;
    }
};