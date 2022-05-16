
#include <iostream>
using namespace std;
bool ratInMaze(char maze[10][10], int m,int n,int i,int j,int sol[][10]){
    if(i==m || j==n){
        sol[m][n] = 1;
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                cout<<sol[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<"\n";
        return true;
    }
    if(i> m || j>n){
        return false;
    }
    if(maze[i][j]=='x')
        return false;
    sol[i][j]=1;
    bool rightSuccess = ratInMaze(maze,m,n,i,j+1,sol);
    bool downSuccess = ratInMaze(maze,m,n,i+1,j,sol);
    sol[i][j]=0;

    if(rightSuccess || downSuccess)
        return true;
    return false;

}
int main() {

    char maze[10][10] = {
        "0000",
        "00x0",
        "0000x",
        "0x00",
    };

    int sol[10][10]={0};
    int m =4,n=4;
    bool ans = ratInMaze(maze,m-1,n-1,0,0,sol);
    if(ans==false)
        cout<<"path does not exist";
	// your code goes here
	return 0;
}


//RatInMaze
