// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<int>V;
    void insert(stack<int>&s,int val,vector<int>&V){
        if(s.empty()){
            V.push_back(val);
            return;
        }
        int v = s.top();
        s.pop();
        insert(s,val,V);
        s.push(v);
    }
    vector<int> Reverse(stack<int> s){
        if(s.empty()) return V;
        int val = s.top();
        s.pop();
        insert(s,val,V);
        Reverse(s);
        return V;
    }
};

// { Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        vector<int> ans=ob.Reverse(St);
        for(int i=0;i<N;i++){
            cout<<ans[i];
            if(i!=N-1) cout<<" ";
        }
        cout<<endl;
    }
}  // } Driver Code Ends