#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, pair<int,int>>node;
vector<int> mergeKSortedArrays(vector<vector<int>>arr){
    vector<int>result;
    priority_queue<node,vector<node>,greater<node>>pq; //min priority queue
    //insert the 0th element of every array in the pq
    for(int i=0;i<arr.size();i++){
        pq.push({arr[i][0],{i,0}});
    }
    //removing values from the heap one by one and add to result  vector
    while(!pq.empty()){
        node current = pq.top();
        pq.pop();
        int element = current.first;
        int x = current.second.first;//row in which ele is present
        int y = current.second.second;//col in which ele is present
        result.push_back(element);
        //you need to push in the PQ the next element of current element x,y+1
        if(y+1<arr[x].size()){
            pq.push({arr[x][y+1],{x,y+1}});
        }
    }
    return result;
}
int main() {
    vector<vector<int>>arr{{2,6,12,15},
    {1,3,14,20},
    {3,5,8,10}};
    vector<int>output = mergeKSortedArrays(arr);
    for(auto x:output){
        cout<<x<<" ";
    }
    return 0;
}
//merge k sorted arrrays
