#include <iostream>
#include<climits>
using namespace std;
//minimum steps to 1 
//n-> n/3 , n/2 or n-1
// top down

int minSteps(int n,int dp[]){
    //base case
    if(n==1){
        return 0;
    }
    if(dp[n]!=0){
        return dp[n];
    }
    int op1,op2, op3;
    op1=op2=op3=INT_MAX;
    if(n%3==0){
        op1 = minSteps(n/3,dp) + 1;
    }
    if(n%2==0){
        op2 = minSteps(n/2,dp) + 1;
    }
    op3 = minSteps(n-1,dp) + 1;
    int ans = min(min(op1,op2),op3);
    return ans;
    //recursive case
}
int main() {
    int n;
    cin>> n;
    int dp[100]={0};

    cout<<minSteps(n,dp);
    //cout<<"Hello World!";
    return 0;
}
//minimum steps to 1 recursive approach top down
