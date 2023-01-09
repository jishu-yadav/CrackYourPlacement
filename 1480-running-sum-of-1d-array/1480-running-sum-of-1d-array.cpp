class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int>ans;
        int result;
        for(int i=0;i<nums.size();i++){
            result+=nums[i];
            ans.push_back(result);
        }
        return ans;
    }
};