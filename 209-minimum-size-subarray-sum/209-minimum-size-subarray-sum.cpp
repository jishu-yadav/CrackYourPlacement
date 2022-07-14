class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int len = INT_MAX;
//         for(int i=0;i<n;i++){
           
//             for(int j=i;j<n;j++){
//                 int sum=0;
//                 for(int k=i;k<=j;k++){
//                     sum+=nums[k];
//                 }
//                 if(sum>=target){
//                     len = min(len,j-i+1);
//                 }
//             }
//         }
//         return (len!=INT_MAX)? len:0;
        //above soln gave tle
        
        int left = 0;
        int sum = 0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            while(sum>=target){
                len = min(len,i+1-left);
                sum-=nums[left++];
            }
        }
        return (len!=INT_MAX)?len:0;
    }
};