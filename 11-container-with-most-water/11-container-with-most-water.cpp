class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int low= 0, high = n-1;
        int max_water = 0;
        while(low<high){
            max_water = max(max_water, min(height[high],height[low])*(high - low) );
            if(height[low]<height[high])
                low++;
            else
                high--;
            
        }
        return max_water;
            
    }
};