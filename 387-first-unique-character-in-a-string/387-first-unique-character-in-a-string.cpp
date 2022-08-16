class Solution {
public:
    int firstUniqChar(string s) {
        map<char,int>mp;
        int firstNonrepeating=-1;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
            //cout<<" *"<<mp[s[i]]<<" ";
        }
        for(int i=0;i<s.size();i++){
            if(mp[s[i]]==1){
               
                firstNonrepeating = i;
                break;
            }
        }
        return firstNonrepeating;
    }
};