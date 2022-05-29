class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
         vector<int>s(n,0);
         long long res=0;
        for(int i=0;i<roads.size();i++){
            s[roads[i][0]]++;
            s[roads[i][1]]++;
        }
        sort(s.begin(),s.end());
        for(int i=0;i<n;i++){
            res+= (long long)(s[i])*(i+1);
        }
        return res;
    }
};///maximum-total-importance-of-roads leetcode biweekly
