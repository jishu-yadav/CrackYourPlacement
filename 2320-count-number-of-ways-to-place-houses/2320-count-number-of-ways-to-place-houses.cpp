class Solution {
public:
    typedef long long ll;
    ll mod = 1e9+7;
    int countHousePlacements(int n) {
        ll house = 1,spaces=1;
        ll total = house+spaces;
        for(int i=2;i<=n;i++){
            house = spaces;
            spaces = total;
            total = (house+spaces)%mod;
        }
        return (total*total)%mod;
    }
};