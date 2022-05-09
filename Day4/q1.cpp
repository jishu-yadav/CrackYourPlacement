class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        int mx=0,sum=0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            sum+=A[i];
            if(sum==0)
            {
                mx=i+1;
            }else{
                if(mp.find(sum)!=mp.end()){
                    mx = max(mx, i-mp[sum]);
                }else{
                    mp[sum] = i;
                }
            }
           
        }
        return mx;
    }
};
//largest subarray with 0 sum
