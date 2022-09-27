class Solution {
public:
    string pushDominoes(string dominoes) {
         int n=dominoes.length();
        //int f[n];
        vector<int>f(n);
        // Populate forces going from left to right
        int force = 0;
        for (int i = 0; i < n; ++i) {
            if (dominoes[i] == 'R') force = n;
            else if (dominoes[i] == 'L') force = 0;
            else force = max(force - 1, 0);
            f[i] += force;
        }
        //right to left
        force = 0;
        for (int i = n-1; i >=0; --i) {
            if (dominoes[i] == 'L') force = n;
            else if (dominoes[i] == 'R') force = 0;
            else force = max(force - 1, 0);
            f[i] -= force;
        }
        string ans="";
        for(auto forces:f){
            //cout<<forces<<" ";
             ans+=(forces > 0 ? 'R' : forces < 0 ? 'L' : '.');
        }
           
        return ans;
    }
};