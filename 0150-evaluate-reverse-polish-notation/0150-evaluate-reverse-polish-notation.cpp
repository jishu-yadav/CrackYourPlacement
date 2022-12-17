class Solution {
public:
    int evalRPN(vector<string>& tokens) {
       stack <long long> st;
        for(int i = 0; i < tokens.size(); i++) {
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                long long f = st.top(); st.pop();
                long long s = st.top(); st.pop();
                if(tokens[i] == "+") st.push(s+f);
                if(tokens[i] == "-") st.push(s-f);
                if(tokens[i] == "*") st.push(s*f);
                if(tokens[i] == "/") st.push(s/f);
            }
            else st.push(stoi(tokens[i]));
        }
        return (int)st.top(); 
    }
};