class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l=0,r=n-1;
        int l_max = 0,r_max=0;
        int result = 0;
        while(l<=r){
            if(r_max<=l_max){
                result+=max(0,r_max-height[r]);
                r_max = max(r_max,height[r]);
                r -= 1;
            }else{
                result+=max(0,l_max-height[l]);
                l_max = max(l_max,height[l]);
                l += 1;
            }
        }
        return result;
    }
};