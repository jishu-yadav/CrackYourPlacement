#include <iostream>

using namespace std;
// int maxSubarraySum(int a[],int n){
//     int dp[n] = {0};
//     dp[0] = a[0];
//     int max_so_far=a[0];
//     if(dp[0]<0)
//         {
//             dp[0] = max_so_far = 0;
//         }
//     for(int i=1;i<n;i++){
//         dp[i] = dp[i-1]+a[i];
//         if(dp[i]<0){
//             dp[i] = 0;
//         }
//         max_so_far = max(max_so_far, dp[i]);
//     }
//     return max_so_far;

// }
int kadanes_max_subarraySum(int a[],int n){
    int cur_sum=0,max_so_far=0;
    for(int i=0;i<n;i++){
        cur_sum+=a[i];
        if(cur_sum< 0){
            cur_sum = 0;
        }
        max_so_far = max(max_so_far, cur_sum);
    }
    return max_so_far;
}
int main() {
    int arr[] = {-3,2,5,-1,6,3,-2,7,-5,2};
    int n = sizeof(arr)/sizeof(int);
    cout<<kadanes_max_subarraySum(arr,n);
    return 0;

}
//maxSubarray sum space optimized . s.c = o(1) t.c = o(n)
