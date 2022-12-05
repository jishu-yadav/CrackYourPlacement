class Solution {
public:
    int pivotIndex(vector<int>& nums) {
//         int i=0,n=nums.size();
//         vector<int>l(n,0);
//         vector<int>r(n,0);
//         int s=0,left=0;
//         int sl=0;
//         int sr=0;
//         int ans = -1;
//         for(i=0;i<n;i++){
//             sl+=nums[i];
//             l.push_back(sl);
//             s+=nums[i];
//         }
//          for(i=0;i<n;i++){
             
//             if(left== s - left-nums[i]){
//                 ans = i;
//             }
//              left+=nums[i];
//         }
//         return ans;
         int total = 0;
        for (int num : nums) total += num;
        int sum = 0;
        for (int i = 0; i < nums.size(); sum += nums[i++])
            if (sum * 2 == total - nums[i])
                return i;
        
        return -1;
    }
};