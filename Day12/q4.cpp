#include <iostream>
#include <climits>
using namespace std;

int minCoins(int n,int coins[],int T, int dp[]){//T is types of coins
    //Base Case
    if(n==0){
        return 0;
    }
    //Lookup
    if(dp[n]!=0){
        return dp[n];
    }
    // rec case
    int ans = INT_MAX;
    for(int i=0;i<T;i++){
        if(n-coins[i]>=0){
            int subprob = minCoins(n-coins[i],coins,T,dp);
            ans = min(subprob + 1,ans);
        }
    }
    dp[n] = ans;
    return dp[n];
}
int main() {
    int N = 15;
    int coins[]={1,7,10};
    int dp[100]={0};
    int T = sizeof(coins)/sizeof(int);
    cout<<minCoins(N,coins,T,dp)<<endl;

    return 0;

    //cout<<"Hello World!";
}
//min coin change problem dp(top down) 31st on ide cb
