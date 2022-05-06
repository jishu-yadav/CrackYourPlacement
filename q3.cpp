//majority element
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
//         int ans=0;
//         map<int,int>mp;
//         for(int i=0;i<n;i++){
//             mp[nums[i]]++;         
//         }
//         for(auto i:mp){
//             if(i.second>n/2){
//                 ans =  i.first;
                
//             }
//         }
//         return ans;
        int count =0;
        int element=0;
        for(int num:nums){
            if(count==0){
                element=num;
            }
            if(element==num){
                count+=1;
            }
            else{
                count-=1;
            }
        }
        return element;
    }
};
