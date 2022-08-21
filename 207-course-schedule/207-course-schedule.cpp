class Solution {
public:
    bool dfs(int i, vector<int> &visited,vector<int>adj[]){
        if(visited[i]==2)
            return false;    
        visited[i] = 1;
        for(auto edge:adj[i]){
            if(visited[edge]==1){
                return true;
            }
            if(dfs(edge,visited,adj))
                return true;
        }        
        visited[i] = 2;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int>visited(n,0);
        vector<int>adj[n];
        for(auto pre:prerequisites){
            adj[pre[1]].push_back(pre[0]);
        }
        for(int i=0;i<n;i++){
            if(visited[i]==0 and dfs(i,visited,adj))
                return false;
        }
        return true;
    }
};