
#include <iostream>
using namespace std;
bool isSafe(int board[][10], int i, int j, int n){
    //check for col
    for(int row=0;row<i;row++){
        if(board[row][j]==1){
            return false;
        }
    }
    int x = i; // left diagonal
    int y = j;
    while(x>=0 && y>=0){
        if(board[x][y]==1)
            return false;
        x--;
        y--;
    }

    // right diagonal 
    while(x>=0 && y<=n){
        if(board[x][y]==1)
            return false;
        x--;
        y++;
    }
    return true;

}
bool solveQueen(int board[][10], int i,int n){
    if(i==n){// base case ... u have successfully place queens in n rows (0 ... n-1);
            // print the board
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==1){
                    cout<<"Q ";
                }else{
                    cout<<"_ ";
                }
            }
            cout<<endl;
        }
        cout<<endl;
        // what if we write false here;
        return false;
    }
    // Recursive Case
    for(int j=0;j<n;j++){
        // I have to check if i,j th position is safe to place the queen or not..
        if(isSafe(board,i,j,n)){
            board[i][j] = 1;
            bool nextQueenRakhPaye = solveQueen(board,i+1,n);
            if(nextQueenRakhPaye){
                return true;
            }
            board[i][j]=0;

        }
    }
    return false;

}
int main() {
    int n;
    cin>>n;

    int board[10][10] = {0};
    solveQueen(board,0,n);

	// your code goes here
	return 0;
}


// nqueen backtracking
