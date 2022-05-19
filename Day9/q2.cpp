
#include <iostream>
#include<list>// it is double linkedlist ///for singly -> <forward_list> is used
using namespace std;
class Queue{
    int cs;
    list<int>l;
public:
    Queue(){
        cs=0;
    }
    bool isEmpty(){
        return cs==0;
    }
    void push(int data){
        l.push_back(data);
        cs++;
    }
    void pop(){
        if(!isEmpty()){
            cs--;
            l.pop_front();
        }

    }
    int front(){
        return l.front();
    }


};

int main() {
    Queue q;
    for(int i=1;i<=10;i++){
        q.push(i);
    }
    while(!q.isEmpty()){
        cout<<q.front()<<" ";
        q.pop();
    }
	// your code goes here
	return 0;
}

// queue using linkedlist
