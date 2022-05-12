class Solution {
public:
    void recursion(vector<int>num,int i,int j,vector<vector<int>>&res){
        if(i==j-1)
        {
            res.push_back(num);
            return ;
        }
        for(int k=i;k<j;k++){
            if(k!=i && num[i]==num[k]) continue;
             swap(num[i],num[k]);
             recursion(num,i+1,j,res);
        }
       
        
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        recursion(nums,0,nums.size(),ans);
        return ans;
    }
};
//permutation ii
