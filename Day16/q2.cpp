#include <iostream>
using namespace std;
int laddersBU(int n,int k){
    int dp[100] = {0};
    dp[0] = 1; //start case
    for(int i=1;i<=n;i++){
        dp[i] = 0;
        for(int j=1;j<=k;j++){
            if(i-j>=0){
                dp[i]+=dp[i-j];
            }
        } 
    }
    return dp[n];
}
int main() {
    int n,k;
    cin>>n>>k;
   
    cout<<laddersBU(n,k);

}
//ladders bottom up appraoch T.C = O(N)
