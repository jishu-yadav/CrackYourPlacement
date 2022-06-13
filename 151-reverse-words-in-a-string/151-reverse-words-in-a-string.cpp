class Solution {
public:
    
    // trim from start
static inline std::string &ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(),
            std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
static inline std::string &rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(),
            std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
    return s;
}

// trim from both ends
static inline std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}

    string reverseWords(string s) {
        if(s.size()==0) return s;
        stack<string>st;
        string str="";
        
        string res;
        
        int n = s.size();
        
        for(int i=0;i<n;i++){
            string word;
            if(s[i]==' ') continue;
            // if((s[i]==' ' or i==n-1) ){
            //     if(i>=1 && s[i-1]==' '){
            //         continue;
            //     }
            //     if(i==n-1  )
            //         st.push(str+s[n-1]);
            //     else
            //         st.push(str);
            //     str = "";
            // }
            // else
            // str+=s[i];
            
            while(i<s.size() && s[i]!=' ')
            {
                word+= s[i];
                i++;
            }
            
            st.push(word);
        }
        
        while(!st.empty()){
            res += st.top();
            st.pop();
            
            if( !st.empty() )
               res+=" ";
           
        }
        //trim(res);
        //res.erase(res.find_first_not_of(" \n\r\t")+1);
        //res.erase(res.find_last_not_of(" \n\r\t")+1);
      
        return res;
    }
};