#include <iostream>
using namespace std;
int ladders_top_down(int n,int k,int dp[]){
    //base case
    if(n==0)
        return 1;
    if(dp[n]!=0){
        return dp[n];
    }
    //rec case

    int ways=0;
    for(int i=1;i<=k;i++ ){
        if(n-i>=0){
            ways+= ladders_top_down(n-i,k,dp);
        }
    }
    return dp[n] = ways;
}
int main() {
    int n,k;
    cin>>n>>k;
    int dp[100] = {0}; 
    cout<<"ways = " <<ladders_top_down(n,k,dp);
    //cout<<"Hello World!";
}
//ladders problem - similar to tribonacci  ( top down approach ) 
