#include <iostream>
using namespace std;
int profit(int wines[],int i,int j,int y){
    //base case
    if(i>j)
        return 0;
    //recursive case
    int op1 = wines[i]*y + profit(wines,i+1,j,y+1);
    int op2 = wines[j]*y + profit(wines,i,j-1,y+1);
    return max(op1,op2);
}
int main() {
  
    int wines[] = {2,3,5,1,4};
    int n = sizeof(wines)/sizeof(int);
    int y = 1;
    cout<< profit(wines,0,n-1,y);
    return 0;
    
}
//Wines problem recursion then dp ...here greedy gives wrong ans...qs was given an array of wines prices ...where each year prices are incresead.. multiplied by the year ... u need to tell the max profit made by selling the wines.
//in one year u can sell only one bottle extreme end or extreme first ...prices of wines inc every year as y th year k: p[i]*y 
