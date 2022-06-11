class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int len=0,n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        sum = sum - x;// to search for this sum a maximum subarray length..
        if(sum==0)
            return n;
        int windowSum = 0;
        int i=0,j=0;
        for(j=0;j<n;j++){
            windowSum+=nums[j];
            
            while(i<n&&windowSum>sum){
                windowSum -= nums[i++];
            }
            if(windowSum==sum){
                len = max(len , j-i +1);
            } 
            
        }
        if(!len){
            return -1;
        }
        else
            return n - len; //remaining sum after removing that maximum subarray Sum
    }
};