class Solution {
public:
    int romanToInt(string s) {
        map<char,int>mp = {{'M',1000}, {'D',500} ,{'C',100} ,{'L',50 }, {'X',10} ,{ 'V',5}, {'I',1}};
        int n = s.size();
        int ans=mp[s.back()];
        for(int i=n-1;i>0;i--){
            if(mp[s[i]] > mp[s[i-1]] ){
                ans-= mp[s[i-1]];
            }
            else
            {
                ans+= mp[s[i-1]];
            }
        }
        return ans;
    }
};