class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans(2,-1);
        int n = nums.size();
        int low = 0, high = n-1;
        if(nums.size()==0)
            return ans;
        //int fPos=0,lPos=0;
        //search for leftmost
        while(low<high){
            int mid = low+(high-low)/2;
            if(nums[mid]<target){
                low = mid+1;
            }
            else
                high = mid;
        }
        if(nums[low]!=target){
            return ans;
        }else
            ans[0]=low;
        //search for rightmost
         high = n-1;
         while(low<high){
            int mid = low+(high-low)/2 +1;
            if(nums[mid]>target){
                high = mid-1;
            }
            else
                low = mid;
        }
        ans[1]=high;
        return ans;
    }
};