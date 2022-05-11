class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
       int last[1000001]={}; int res= INT_MAX;
       int n = cards.size();
       for(int i=0;i<n;i++){
           if(last[cards[i]])
               res = min(res, i - last[cards[i]] + 2);
           last[cards[i]]=i+1;
       }
        return res==INT_MAX? -1: res;
    }
};
// minimumcardpickup
