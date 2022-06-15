class Solution {
public:
    void dfs(vector<vector<int>>&adj,int i,vector<bool>&visited){
        visited[i] = true;
        for(auto j:adj[i]){
            if(!visited[j])
            dfs(adj,j,visited);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        //count the connected components
        int edges = connections.size();
        
        if(edges - (n-1) < 0)
            return -1;
        
        vector<vector<int>>adj(n);
        vector<bool>visited(n,false);
        
        //adj list creation from given edge connections
        // for(int i=0;i<n;i++){
        //     adj[i][0].push_back(adj[i][1]);
        //     adj[i][1].push_back(adj[i][0]);
        // }
        for(auto i:connections){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        int count=0;
        //now counting components ...musing dfs
        for(int i=0;i<n;i++){
            if(!visited[i]){
                count++;
                visited[i] = true;
                dfs(adj,i,visited); 
            }
        }
        return count-1;
    }
};