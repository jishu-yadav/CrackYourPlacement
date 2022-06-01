class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int>v;
        int s=0;
        for(int i=0;i<nums.size();i++){
            s+=nums[i];
            v.push_back(s);
        }
        return v;
    }
};//running sum arrays
