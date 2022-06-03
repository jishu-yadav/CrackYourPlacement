class Solution {
    vector<vector<int>> ans;
public:
    void fun(vector<int>nums,int n,vector<int>v,int i=0){
        if(i==n){
            ans.push_back(v);
            return;
        }
        if(v.empty()||nums[i]!=v.back() ){
            fun(nums,n,v,i+1);
        }
        v.push_back(nums[i]);
        fun(nums,n,v,i+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>v;
        sort(nums.begin(),nums.end());
        
        fun(nums,nums.size(),v);
        return ans;
    }
  
};
