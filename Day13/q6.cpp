#include <iostream>
#include<vector>
using namespace std;
void print(vector<int>v){
    for(auto x:v){
        cout<<x <<" ";
    }
    cout<<endl;
}
void buildheap(vector<int>&v){
    
    for(int i=2;i<v.size();i++){
        int idx = i;
        int parent = i/2;
        while(idx>1 and v[idx] > v[parent]){
            swap(v[idx],v[parent]);
            idx = parent;
            parent = parent/2;
        }
    }
}
int main() {
    vector<int>v{-1,10,20,5,6,1,8,9,4}; // heap ...the elements starts from second index
    print(v);
    buildheap(v);
    print(v);

    //cout<<"Hello World!";
}
//build heap from an array
