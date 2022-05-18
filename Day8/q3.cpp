
#include <iostream>
using namespace std;

void generate_strings(char *in, char *out,int i,int j){
    if(in[i]=='\0'){
        out[j]='\0';
        cout<<out<< endl;
        return ;

    }
    int digit = in[i]-'0';
    char ch = digit+'A'-1;
    //rec case 1
    //one digit at a time
    out[j] = ch;
    generate_strings(in,out,i+1,j+1);
    
    //2.two digit at a time
    if(in[i+1]!='\0'){
        int secondDigit = in[i+1]-'0';
        int no = digit*10+secondDigit;
        if(no<=26){
            ch = no + 'A' -1;
            out[j] = ch;
            generate_strings(in,out,i+2,j+1);
        }
    }
    
    return;
}
int main() {
	// your code goes here
    char in[100];
    cin >> in;
    char out[100];
    generate_strings(in,out,0,0);
	return 0;
}

//String generation Acode recursion
