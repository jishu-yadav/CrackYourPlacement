class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int t = nums1.size();
        stack<int>st;
        int n = nums2.size();
        unordered_map<int,int>mp;
        vector<int>nge(n,-1);
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&st.top()<nums2[i]){
                st.pop();
            }
            if(st.empty()==false)
            {
                nge[i] = st.top();
                mp[nums2[i]]=st.top();
            }
            st.push(nums2[i]);
            
        }
    
        for(int i=0;i<t;i++){
            if(mp.find(nums1[i])!=mp.end())
                nums1[i]=mp[nums1[i]];
            else
                nums1[i] = -1;
        }
        return nums1;
    }
};