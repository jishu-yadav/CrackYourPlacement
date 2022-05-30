#include <iostream>
#include <queue>//pq is present in this header file
using namespace std;
int main() {
    int n ;
    cin>> n;
    //cout<<"hello";
    priority_queue<int,vector<int>,greater<int>>pq;//min pq
    //priority_queue<int>pq;//max heap / pq
    for(int i=1;i<=n;i++){
        int no;
        cin >> no;
        pq.push(no);
    }
    while(!pq.empty()){
        cout<< pq.top()<<" ";
        pq.pop();
    }
    return 0;
}
//pq print
