class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n =s.length(),c=0;
        if(n<k) return s;
        stack<pair<char,int>>st;
        for(int i=0;i<n;i++){
           if(st.empty() || st.top().first!=s[i] ) st.push({s[i],1});
           else{
                auto prev = st.top();
                st.pop();
                st.push({s[i],prev.second+1});
            }
            if(st.top().second==k) st.pop();
        } 
        
        
        s="";
        n = st.size();
     while(!st.empty()){
           auto cur = st.top();
           st.pop();
           while(cur.second--){
               s.push_back(cur.first);
           }
       } 
        reverse(s.begin(),s.end());
        return s;
    }
};
