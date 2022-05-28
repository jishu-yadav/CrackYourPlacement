class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int Xor = 0,i =0;
        for(i=0;i<nums.size();i++){
            Xor=Xor ^i ^ nums[i];
        }
        return Xor ^ i;
        
        //OR
        // vector<int>v(nums);
        // int k =0;
        // sort(nums.begin(),nums.end());
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]!=i){
        //         k = i;
        //         break;
        //     }
        //     else{
        //         k=nums.size();
        //     }
        // }
        // return k;
    }
};//find the missiing number
