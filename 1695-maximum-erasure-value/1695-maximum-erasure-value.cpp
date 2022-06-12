class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
//         int l=0,r=0,mx=0;
//         int n = nums.size(),sum=0;
//         unordered_set<int>st;
//         for(int r=0;r<n;r++){
//             sum+=nums[r];
//             //cout<<sum<<" ";
//             st.insert(nums[r]);
//             if(st.find(nums[r])!=st.end()){
//                 while(l<r&&st.find(nums[r])!=st.end()){
                    
//                     l++;
                    
//                     sum-=nums[r];
//                     cout<<sum<<" ";
//                     st.erase(nums[r]);
                    
//                     mx = max(mx,sum);
                    
                    
//                     sum+=nums[l];
//                     st.insert(nums[l]);
                    
//                     mx = max(mx,sum);
//                 }
//             }   
//         }
        
//         return mx;
        
         int mx=0;
        int n = nums.size(),sum=0;
        unordered_set<int>st;
        for(int l=0,r=0,window=0;r<n;r++){
           while(st.find(nums[r])!=st.end()){
               st.erase(nums[l]);
               window-=nums[l];
               l++;
           }
            st.insert(nums[r]);
            window+=nums[r];
            mx = max(mx, window);
            
        }
        
        return mx;
        
    }
};