#include <iostream>
#include<vector>
using namespace std;
void print(vector<int>v){
    for(auto x:v){
        cout<<x <<" ";
    }
    cout<<endl;
}
bool minHeap = false;
bool compare(int a,int b){
    if(minHeap)
        return a<b;
    else 
        return a>b;
}
void buildheap(vector<int>&v){
    //o(nlogn)
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
void heapify(vector<int>&v,int idx){
    int left = 2*idx;
    int right = left+1;
    int min_idx = idx;
    int last = v.size()-1;
    if(left<=last and compare(v[last],v[idx]))
        min_idx=left;
    if(right<=last and compare(v[right],v[min_idx]))
        min_idx = right;
    if(min_idx!=idx)
    {
        swap(v[idx],v[min_idx]);
        heapify(v,min_idx);
    }
}

void buildheapOptimized(vector<int>&v){
    for(int i=(v.size()-1/2);i>=1;i--){
        heapify(v,i);
    }
}
int main() {
    vector<int>v{-1,10,20,5,6,1,8,9,4}; // heap ...the elements starts from second index
    print(v);
    //buildheap(v);
    buildheapOptimized(v);
    print(v);

    //cout<<"Hello World!";
}
// build heap from aaray in O(n) time complexity
