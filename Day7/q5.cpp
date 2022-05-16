
#include <iostream>
using namespace std;
void generateSubsequences(char *in, char* out,int i,int j){
    if(in[i]=='\0'){
        out[j]='\0';
        cout<<out<<endl;
        return;
    }
    out[j]=in[i];
    generateSubsequences(in,out,i+1,j+1);
    //to backtrack do in[i]='\0' or ...
    generateSubsequences(in,out,i+1,j);

}
int main() {
	// your code goes here
    char input[]="abc";
    char output[100];
    generateSubsequences(input,output,0,0);
	return 0;
}


// subsequnce generation using recursion n backtracking
