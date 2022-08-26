class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string num = sorted(n);
        for(int i=0;i<32;i++){
            if(num==sorted(1<<i))
                return true;
        }
        return false;
    }
    string sorted(int n){
        string s = to_string(n);
        sort(s.begin(),s.end());
        return s;
    }
};