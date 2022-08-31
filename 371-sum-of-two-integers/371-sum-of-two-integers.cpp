class Solution {
public:
    int getSum(int a, int b) {
       //return a+b;
        while(b) {
            unsigned c = a&b;
            a ^= b;
            b = c << 1;
        }
        return a;
    }
};