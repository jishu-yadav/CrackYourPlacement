class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        int i=0,j=0;
        set<char>st;
        int n = str.size();
        int max_len=0;
        while(j<n){
            if(st.count(str[j])==0){
                st.insert(str[j]);
                j++;
                max_len = max(max_len , (int)st.size());
            }
            else{
                st.erase(str[i]);
                i++;
            }
        }

    // TODO: Write your code here
    return max_len;
    }
};