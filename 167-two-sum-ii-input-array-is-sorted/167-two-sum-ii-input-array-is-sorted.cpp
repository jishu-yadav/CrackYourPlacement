class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map< int , int >mp;
        for(int i=0;i<nums.size();i++){
            if(mp.find(target-nums[i])!=mp.end()){
                return {mp[target-nums[i]]+1 , i+1};
            }
            mp[nums[i]] = i;
        }
        vector<int>v;
        return v;
    }
};