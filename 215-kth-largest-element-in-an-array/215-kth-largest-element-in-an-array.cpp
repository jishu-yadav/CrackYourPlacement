class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>>pq(nums.begin(),nums.end());
        int x=0,i=0;
        while(i < k && !pq.empty()){
            x = pq.top();
            pq.pop();
            i++;
        }
        return x;
    }
    
};