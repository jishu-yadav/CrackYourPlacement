class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mx = 0;
        int n = prices.size();
        int mn = INT_MAX;
        for(int i=0;i<n;i++){
            mn = min(mn,prices[i]);
            mx= max(mx,prices[i]-mn);
        }
        return mx;
    }
};