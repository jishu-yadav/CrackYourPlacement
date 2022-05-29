class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        set<char>st;
        for(int i=0;i<target.size();i++){
            st.insert(target[i]);
        }
        unordered_map<char,int>mp;
        for(char i:s){
            mp[i]++;
        }
        unordered_map<char,int>mpt;
        for(char i:target){
            mpt[i]++;
        }
        int mn=INT_MAX;
        int n =s.size(),m = target.size();
        int x=0,f=0;
        for(auto i: mpt){
            char ch = i.first;
            if(mp.find(ch)==mp.end()){
                f=-1;
                break;
            }
           
            else{
                if(mn > (mp[ch])/(mpt[ch]) ) {
                    mn = (mp[ch])/(mpt[ch]);
                }
            }
        }
        if(f==-1)
            return 0;
        if(st.size()==target.size())
            return mn;
        
    }
};//rearrange to make target string
