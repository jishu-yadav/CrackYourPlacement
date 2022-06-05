class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>pq(nums.begin(),nums.end());
        int x=0,i=1;
        while(!pq.empty()&&i<=k){
             x  = pq.top();
            pq.pop();
            i++;
        }
        return x;
    }
};