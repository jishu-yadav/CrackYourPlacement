//pallindromes
class Solution {
public:
    bool isPalindrome(int x) {

        string s = to_string(x);
        string s1=s;
        reverse(s1.begin(),s1.end());
        return s1==s;
    }
};
