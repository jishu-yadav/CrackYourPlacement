class Solution {
public:
   bool static compare(pair<int,int>&p1,pair<int,int>&p2) {
        return p1.second > p2.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
       unordered_map<int, int> hash;
        vector<pair<int, int>> v;
        vector<int> ans;
         for(auto n:nums) {
            hash[n]++;
        }
      
        // Make pair of Value and its frequency
        for(auto i:hash) {
            v.push_back({i.first, i.second});
        }
        
        sort(v.begin(),v.end(),compare);
        for(int p=0;p<k;p++){
            ans.push_back(v[p].first);
        }
        return ans;
    }
};