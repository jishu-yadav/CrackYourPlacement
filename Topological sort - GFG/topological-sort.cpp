// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order.
// 	 bool dfs(int i,vector<int>&visited,vector<int>adj[],vector<int>&ans){
//         if(visited[i] == 1)
//             return true;
//         if(visited[i]==0){
//             visited[i] = 1;
//             for(auto edge:adj[i]){
//                 if(dfs(edge,visited,adj,ans)){
//                     return true;
//                 }
//             }
//         ans.push_back(i);
//         visited[i] = 2;
//         }
       
//         return false;
//     }
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	   // int n = V;

    //     vector<int>visited(n,0);
    //     vector<int>ans;
    //     for(int i=0;i<n;i++){
    //         if(dfs(i,visited,adj,ans)){
    //             return {};
    //         }
    //     }
    //     return ans;
    vector<int>in_degree(V,0);
    vector<int>ans;
    for(int i=0;i<V;i++){
        for(int x: adj[i]){
            in_degree[x]++;
        }
    }
    queue<int>q;
    for(int i=0;i<V;i++){
        if(in_degree[i]==0){
            q.push(i);
        }
    }
    
    while(!q.empty()){
        int u = q.front();
        q.pop();
        ans.push_back(u);
        for(int v:adj[u]){
            if(--in_degree[v]==0){
                q.push(v);
            }
        }
    }
	 return ans;
	}
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends