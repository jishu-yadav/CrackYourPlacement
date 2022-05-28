#include <iostream>

using namespace std;
int maxSubarraySum(int a[],int n){
    int dp[n] = {0};
    dp[0] = a[0];
    int max_so_far=a[0];
    if(dp[0]<0)
        {
            dp[0] = max_so_far = 0;
        }
    for(int i=1;i<n;i++){
        dp[i] = dp[i-1]+a[i];
        if(dp[i]<0){
            dp[i] = 0;
        }
        max_so_far = max(max_so_far, dp[i]);
    }
    return max_so_far;

}
int main() {
    int arr[] = {-3,2,5,-1,6,3,-2,7,-5,2};
    int n = sizeof(arr)/sizeof(int);
    cout<<maxSubarraySum(arr,n);
    return 0;

}
//max subarray sum with t.c = o(n)
