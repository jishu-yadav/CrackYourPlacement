
#include <iostream>
#include<queue>
using namespace std;

int main() {
    queue<char>q;
    int freq[27] = {0};
    //running a stream until a '.'
    char ch;
    cin>> ch;
    cout<<"hello";
    while(ch!='.'){
        //logic will go here
        //insert ch into q and freq table
        q.push(ch);
        freq[ch-'a']++;
        //query
        while(!q.empty()){
            int idx = q.front()-'a';
            if(freq[idx]>1)
                q.pop();
            else{
                cout<<q.front()<<"\n";
                break;
            }
           
        }
         if(q.empty()){
                cout<<"-1\n";
            }
        cin >> ch;
    }
	// your code goes here
	return 0;
}

//1st nonrep char in stream plzz check once more
