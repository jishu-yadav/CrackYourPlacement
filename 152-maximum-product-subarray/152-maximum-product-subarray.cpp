class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxVal = nums[0];
        int minVal = nums[0];
        int maxProduct = nums[0];
        
        for(int i=1;i<nums.size();++i){
            if(nums[i]<0)
                swap(maxVal,minVal);
            
            maxVal = max(nums[i],nums[i]*maxVal);
            minVal = min(nums[i],nums[i]*minVal);
            
            maxProduct = max(maxProduct, maxVal);
        }
        return maxProduct;
    }
};