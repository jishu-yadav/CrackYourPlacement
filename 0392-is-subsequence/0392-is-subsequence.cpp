class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0,j=0;
        int m = s.size(), n = t.size();
        while(i<m&&j<n){
            if(s[i]==t[j]){
                i++;
            }
            j++;
        }
        return i==m?1:0;
//         map<char,int>mp;
//         map<char,int>mp2;
//         for(int i=0;i<s.size();i++){
//             mp[s[i]]++;
//         }
//         for(int i=0;i<t.size();i++){
//             mp2[t[i]]++;
//         }
        
//         for(int i=0;i<s.size();i++){
//             if(mp[s[i]] > mp2[s[i]] ){
//                 return false;
//             }
//         }
//         return true;
    }
};