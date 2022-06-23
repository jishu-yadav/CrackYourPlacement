class Solution {
public:
    
    void dfs(int i,int j,vector<vector<char>>&grid){
        if(i<0 || j<0 || i>=grid.size()|| j>=grid[0].size() || grid[i][j]!='1')
            return;
        grid[i][j] = '0';
        dfs(i+1,j,grid);
        dfs(i,j+1,grid);
        dfs(i-1,j,grid);
        dfs(i,j-1,grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size()==0){
            return 0;
        }
        int count=0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    count++;
                    dfs(i,j,grid);
                }
            }
        }
        return count;
    }
};