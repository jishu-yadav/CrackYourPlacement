class Solution {
public:
    bool dfs(int i,vector<int>&visited,vector<int>adj[]){
        if(visited[i] == 1)
            return true;
        if(visited[i]==0){
            visited[i] = 1;
            for(auto edge:adj[i]){
                if(dfs(edge,visited,adj)){
                    return true;
                }
            }
        }
        visited[i] = 2;
        return false;
        
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int>adj[n];
        for(auto pre:prerequisites){//edges insertion
            adj[pre[1]].push_back(pre[0]);
        }
        
        vector<int>visited(n,0);
        
        for(int i=0;i<n;i++){
            if(dfs(i,visited,adj)){
                return false;
            }
        }
        return true;
        
    }
};