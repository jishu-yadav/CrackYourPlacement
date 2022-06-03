class Solution {
public:
    void permutations(int i,vector<vector<int>>&ans,vector<int>&nums,int n){
         if(i==n){
             ans.push_back(nums);
             return;
         }
         for(int j=i;j<=n;j++){
             swap(nums[i],nums[j]);
             permutations(i+1,ans,nums,n);
             swap(nums[i],nums[j]);
         }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        permutations(0,ans,nums,nums.size()-1);
        return ans;
    }
};