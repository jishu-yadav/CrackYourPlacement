//
class Solution {
public:
    string removeDigit(string number, char digit) {
       for(int i=0;i<number.size();i++){
           if(number[i]==digit && number[i+1]>number[i]){
               return number.substr(0,i)+ number.substr(i+1);
           }
       }
        int last_f = number.rfind(digit);
        return number.substr(0,last_f)+ number.substr(last_f+1);
    }
};
// remove a digit n maximize the number
