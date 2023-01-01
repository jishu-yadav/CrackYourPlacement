class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<char,int>m1;
        vector<int>a;
        map<string,int>m2;
        vector<int>b;
        int x=0,y=0;
        for(auto i:pattern){
            if(m1.find(i)!=m1.end()){
             a.push_back(m1[i]);
            }
            else
            {
             m1[i] = x;
             a.push_back(x);  
             x++;
            }
        }
        
    string word;
    stringstream iss(str);
    while (iss >> word)
    {
        if(m2.find(word)!=m2.end()){
             b.push_back(m2[word]);
            }
            else
            {
             m2[word] = y;
             b.push_back(y);  
             y++;
            }
        
    }
    // cout<<a[3]<< " "<<b[3]<<" "; 
    
    if(a==b)
        return true;
    else
        return false;
    }
};