
#include <iostream>
using namespace std;
int profit(int n,int c,int *wt,int *prices){
    if(n==0 || c==0){
        return 0;
    }
    int ans=0;

    int inc ,exc = -1;
    if(wt[n-1]<=c)
        inc = prices[n-1] + profit(n-1,c-wt[n-1],wt,prices);
    exc = profit(n-1,c,wt,prices);
    ans = max(inc,exc);
    return ans;
}
int main() {
	// your code goes here
    int weights[] = {1,2,3,5};
    int prices[] = {40,20,30,100};
    int n = 4 ,c = 7;
    cout << profit(n,c,weights,prices)<< endl ;
 	return 0;
}

// 0-1 knapsack recursion
