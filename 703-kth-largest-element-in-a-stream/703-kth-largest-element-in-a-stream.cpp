class KthLargest {
public:
   int n;
     priority_queue<int,vector<int>,greater<int>>pq;
    KthLargest(int k, vector<int>& nums) {
        n=k;
        for(auto i:nums){
            pq.push(i);
            if(pq.size()>k)
                pq.pop();
        }
        
    }
    
    int add(int val) {
        pq.push(val);
        int x;
        if(pq.size()>n)
            pq.pop();
        // while(n-->0){
        //     x = pq.top();
        //     pq.pop();
        // }
        return pq.top();
        
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */