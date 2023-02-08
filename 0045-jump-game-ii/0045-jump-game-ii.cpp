class Solution {
public:
    int jump(vector<int>& nums) {
        int size=nums.size();
        int jumps=0;
        int currstart=0;
        int currend=0;
        
        for(int i=0;i<size-1;i++){
            currstart=max(currstart,i+nums[i]);
            if(i==currend){
                currend=currstart;
                jumps++;
            }
            if(currend>=size)
                break;
        }
        return jumps;
    }
};