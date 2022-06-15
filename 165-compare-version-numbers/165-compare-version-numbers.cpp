class Solution {
public:
    
    int compareVersion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        
        int i=0,j=0; // variables used for moving
        
        int number1=0,number2=0;
         
        while(i<n1 || j<n2){
            // generating number between dots of string 1
            while(i<n1 && s1[i]!='.'){
                number1 = 10*number1 + (s1[i]-'0');
                i++;
            }
            // generating number between dots of string 2
            while(j<n2 && s2[j]!='.'){
                number2 = 10*number2 + (s2[j]-'0');
                j++;
            }
            
            if(number1 > number2){
                return 1;
            }
            if(number1 < number2){
                return -1;
            }
            
            number1= 0;
            number2=0;
            i++;
            j++;
        }
        return 0;
        
    }
};