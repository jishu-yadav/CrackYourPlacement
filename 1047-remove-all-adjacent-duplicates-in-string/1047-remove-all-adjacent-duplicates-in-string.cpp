class Solution {
public:
    string removeDuplicates(string s) {
        
        
        
//         string ans;
        
//         for(int i = 0 ; i < s.size() ; i++)
//         {
//             if(ans.size() && ans.back() == s[i])
//                 ans.pop_back();
//             else
//                 ans.push_back(s[i]);
//         }
        
//         return ans;
        
        string st;
        // stack<char>st;
        st.push_back(s[0]);
        for(int i=1;i<s.size();i++){
            if(st.size() && st.back()==s[i]){
                st.pop_back();
            }
            else{
                st.push_back(s[i]);
            }
        }
        
        // string r="";
        // for(int i=0;i<st.size();i++){
        //     r+=st.top();
        //     st.pop();
        // }
        // cout<<r<<" ";
        // return r;
        return st;
        
    }
};