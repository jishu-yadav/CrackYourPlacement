class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
     sort(nums.begin(),nums.end());
     int n = nums.size(),c=1;  
     int mx = 0;
     set<int>st;
     if(n<=1)
         return n;
     for(int i=0;i<n-1;i++){
         if(nums[i]+1==nums[i+1] || nums[i]==nums[i+1]){
             c++;
             st.insert(nums[i]);
             st.insert(nums[i+1]);
             int siz=st.size();
             mx= max(mx,siz);
         }
         else{
             c=1;
             st.clear();
         }
     }
        return mx;
    }
};