
int findMinimumCoins(int amount) 
{
    // Write your code here
     int a[]={1, 2, 5, 10, 20, 50, 100, 500, 1000};
     int n = 9;
     vector<int>ans;
    
    for(int i=n-1;i>=0;i--){
        while(amount>=a[i]){
            amount-=a[i];
            ans.push_back(a[i]);
        }
    }
    return ans.size();
    
    
}
// findminimumcoins greedy
