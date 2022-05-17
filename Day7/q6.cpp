
#include <iostream>
using namespace std;
void generateBrackets(char *out,int idx,int open,int close,int n){
    if(idx == 2*n){
        out[idx]='\0';
        cout<<out<<endl;
        return;
    }
    if(open<n){
        out[idx]='(';
        generateBrackets(out,idx+1,open+1,close,n);

    }
     if(close<open){
        out[idx]=')';
        generateBrackets(out,idx+1,open,close+1,n);
        
    }
    return;
}
int main() {
	// your code goes here
    int n;
    cin>> n;
    char out[1000];
    int idx = 0;
    generateBrackets(out,idx,0,0,n);
	return 0;
}

//7.GenerateBrackets with two conditions 1. open < n 
//2. close<open

