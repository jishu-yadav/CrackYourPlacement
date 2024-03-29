class Solution {
public:
    void eraseIslands(vector<vector<char>>&grid,int i,int j){
         int m = grid.size(),n = grid[0].size();
        if(i<0 || i==m || j<0 || j==n || grid[i][j]=='0')
            return;
        grid[i][j] = '0';
        eraseIslands(grid,i+1,j);
        eraseIslands(grid,i-1,j);
        eraseIslands(grid,i,j+1);
        eraseIslands(grid,i,j-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = m?grid[0].size():0;
        int islands = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    islands++;
                    eraseIslands(grid,i,j);
                }
            }
        }
        return islands;
        
        //with bfs :!
        // int islands = 0;
        // int offsets[] = {0,1,0,-1, 0};
        // int n = grid.size();
        // int m = grid[0].size();
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         if(grid[i][j]=='1'){
        //             islands++;
        //             grid[i][j] = '0';
        //             queue<pair<int,int>>todo;
        //             todo.push({i,j});
        //             while(!todo.empty()){
        //                 pair<int,int>p = todo.front();
        //                 todo.pop();
        //                 for(int k=0;k<4;k++){
        //                     int r = p.first+offsets[k],           c=p.second+offsets[k+1];
        //                     if(r>=0 && r<n &&c>=0&&c<m && grid[r][c]=='1'){
        //                         grid[r][c] = '0';
        //                         todo.push({r,c});
        //                     }
        //                 }
        //             }
        //         }
        //     }
        // }
        // return islands;
    }
};