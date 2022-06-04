// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void helper(int i,int j,string s,vector<string>&ans,vector<vector<int>>m,int n){
        if(i<0 || j<0 || i>=n || j>=n)
            return;
        if(m[i][j]==0)
            return;
        if(i==n-1 and j==n-1){
            ans.push_back(s);
            return;
        }
        m[i][j] = 0;
        helper(i,j+1,s+'R',ans,m,n);
        helper(i,j-1,s+'L',ans,m,n);
        helper(i+1,j,s+'D',ans,m,n);
        helper(i-1,j,s+'U',ans,m,n);
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string>ans;
        string s="";
        helper(0,0,s,ans,m,n);
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends