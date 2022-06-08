class Solution {
    int cnt=0;
public:
    bool isPallindrome(string s,int i,int j){
        while(i<j){
            if(s[i++]!=s[j--])
                return false;
        }
        return true;
    }
    int removePalindromeSub(string s) {
        if(s.size()==0)
            return 0;
        if(isPallindrome(s,0,s.size()-1))
            return 1;
        return 2;//cuz if we remvoe all ones in one go we will left with b's so just 2 operations
        
    }
};