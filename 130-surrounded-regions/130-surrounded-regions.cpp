class Solution {
public:
    void dfs(vector<vector<char>>&board,int i,int j,int m,int n){
        if(i>=m||j>=n||i<0||j<0||board[i][j]!='O') return;
        board[i][j] = '#';
        dfs(board,i,j-1,m,n);
        dfs(board,i,j+1,m,n);
        dfs(board,i+1,j,m,n);
        dfs(board,i-1,j,m,n);
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();//rows
        if(m==0) return;
        int n = board[0].size();
        //col 1 and col last
        for(int i=0;i<m;i++){
            if(board[i][0]=='O')
                dfs(board,i,0,m,n);
            
            if(board[i][n-1]=='O')
                dfs(board,i,n-1,m,n);
        }
        // row 1 and row last
        for(int j=0;j<n;j++){
            if(board[0][j]=='O')
                dfs(board,0,j,m,n);
            if(board[m-1][j]=='O')
                dfs(board,m-1,j,m,n);
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }else if(board[i][j]=='#'){
                    board[i][j] = 'O';
                }
            }
        }
        
        
        
    }
};