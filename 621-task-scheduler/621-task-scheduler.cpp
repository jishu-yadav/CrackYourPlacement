class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>mp;
        int mx = 0;
        for(auto t:tasks){
            mp[t]++;
            mx = max(mx, mp[t]);
        }
        int ans = (mx-1)*(n+1);
        for(auto it:mp){
            if(it.second==mx)
                ans++;
        }
        return max((int)tasks.size(), ans);
        
    }
};