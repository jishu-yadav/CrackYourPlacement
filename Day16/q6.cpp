#include <iostream>
using namespace std;

int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};
void printMat(int ip[][50]){
    for(int i=0;i<50;i++){
        for(int j=0;j<50;j++){
            cout<<ip[i][j]<<" ";
        }
        cout<<endl;
    }
}
void flood_Fill(int mat[][50], int i,int j,char ch,char color){
    //Base -case : Matrix boundaries
    if(i<0 || j<0 || i>=R || j>=C){
        return;
    }
    //Figure boundaries
    if(mat[i][j]!=ch){
        return;
    }
    //Recursive case
    mat[i][j] = color;
    
    for(int k=0;k<4;k++){
        flood_fill(mat,i+dx[k],j+dy[k],ch,color);
    }
} 
int main() {
    int R,C;
    cin >> R>> C;
    char input[15][50];
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin>>input[i][j];
        }
    }
    printMat(input);

    return 0;

}
//flood fill agorithm there is some err plz resolve jishuuuuuu
