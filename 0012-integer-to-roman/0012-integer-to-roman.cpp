class Solution {
public:
    string intToRoman(int num) {
         string s;
        map<char,int>{{'M',1000},{'D',500},{'C',100},{'L',50},{'X',10},{'V',5},{'I',1}};
    const int val[13] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
    const string rom[13] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    string ans="";
        for(int i=0;num;i++)
        while(num>=val[i])ans+=rom[i], num-=val[i];
        return ans;
    }
};