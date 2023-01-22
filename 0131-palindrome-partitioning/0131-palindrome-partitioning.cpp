class Solution {
public:
    bool palindromeCheck(string &s,int i,int j){
        while(i<j){
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    void partitionHelper(int start,vector<string>&p,string &s,vector<vector<string>>&ans){
        if(start>=s.size()) ans.push_back(p);
        
        for(int end = start;end<s.size();end++){
            if(palindromeCheck(s,start,end)){
                p.push_back(s.substr(start,end-start+1));
                partitionHelper(end+1,p,s,ans);
                p.pop_back();
            }
        }
        
    }
    vector<vector<string>> partition(string s) {
        int l=s.size();
        vector<vector<string>>ans;
        vector<string>p;
        partitionHelper(0,p,s,ans);
        return ans;
    } 
    
};