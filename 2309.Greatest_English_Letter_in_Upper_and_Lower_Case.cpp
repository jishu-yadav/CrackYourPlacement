class Solution {
public:
    string greatestLetter(string s) {
        vector<int>chu(26,0);
        vector<int>chl(26,0);
        int n = s.size();
        for(int i=0;i<n;i++){
            if(isupper(s[i])){
                chu[s[i]-'A']=1;
            }
            if(islower(s[i])){
                chl[s[i]-'a']=1;
            }
        }
        string ans="";
        for(int i=25;i>=0;i--){
            if(chu[i]==1&&chl[i]==1){
                ans = i +'A';
                break;
            }
        }
        return ans;
    }
};
