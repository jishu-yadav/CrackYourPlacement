class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <long long> s;
        for(long long i=0 ; i<tokens.size(); i++){
            if(tokens[i]!="+"&&tokens[i]!="-"&&tokens[i]!="*"&&tokens[i]!="/"){
                s.push(stoi(tokens[i]));
                continue;
            }
            
            long long op2 = s.top();
            s.pop();
            long long op1 = s.top();
            s.pop();
            
            if(tokens[i]=="+")
                s.push(op1 + op2);
            else if (tokens[i]=="-")
                s.push(op1 - op2);
            else if (tokens[i]=="*")
                s.push(op1 * op2);
            else 
                s.push(op1 / op2);
        }
        return s.top();
    }
};