class Solution {
public:
    void helper(int i,int target,vector<int>&arr,vector<vector<int>>&ans,vector<int>&ds){
        if(target==0){
            ans.push_back(ds);
            return;
        }
        for(int idx=i;idx<arr.size();idx++){
            
            if(idx>i && arr[idx]==arr[idx-1]) continue;
           
            if(arr[idx]>target) break;
           
            ds.push_back(arr[idx]);
            helper(idx+1,target-arr[idx],arr,ans,ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        sort(candidates.begin(),candidates.end());
        vector<int>ds;
        helper(0,target,candidates,ans,ds);
        return ans;
    }
};