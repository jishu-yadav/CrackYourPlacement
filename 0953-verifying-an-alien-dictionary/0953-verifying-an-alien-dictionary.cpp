class Solution {
public:
    unordered_map<char, int> m;
    bool isAlienSorted(vector<string>& words, string order) {
        
        for(int i = 0; i < size(order); i++) m[order[i]] = i; 
        for(int i = 0; i < size(words)-1; i++){
            if(!check(words[i],words[i+1])) return false;
        }
        return true;
    }
    bool check(string &a,string &b){
        int i=-1;
        while(++i < size(a) && i<size(b)){
            if(m[a[i]]!=m[b[i]]) return m[a[i]]<m[b[i]];
        }
        return size(a)<=size(b);
    }
};