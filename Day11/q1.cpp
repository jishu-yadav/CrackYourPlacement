class Solution {
public:
    bool ispal(string s){
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i++]!=s[j--]){
                return false;
            }
        }
        return true;
    }
    int countSubstrings(string s) {
        int n = s.size(),c=0;
        for(int i=0;i<n;i++){
            for(int j=1;j<=n-i;j++){
                
                if(ispal(s.substr(i,j)))
                {

                    c++;
                }
            }
        }
        return c;
    }
};/pallindromic substrings
