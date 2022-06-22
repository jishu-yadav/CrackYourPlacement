class Solution {
public:
    bool dfs(int i,vector<int>&visited,vector<int>adj[],vector<int>&ans){
        if(visited[i] == 1)
            return true;
        if(visited[i]==0){
            visited[i] = 1;
            for(auto edge:adj[i]){
                if(dfs(edge,visited,adj,ans)){
                    return true;
                }
            }
        ans.push_back(i);
        visited[i] = 2;
        }
       
        return false;
        
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int>adj[n];
        for(auto pre:prerequisites){//edges insertion
            adj[pre[0]].push_back(pre[1]);
        }
        
        vector<int>visited(n,0);
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(dfs(i,visited,adj,ans)){
                return {};
            }
        }
        return ans;
        
    }
};