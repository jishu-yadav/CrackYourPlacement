class MyQueue {
   stack<int>s1;
    stack<int>s2;
public:
    
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        int res = peek();
        s2.pop();
        return res;
    }
    
    int peek() {
        if(s2.empty())
        while(!s1.empty()){
        int x=s1.top();
        s1.pop();
        s2.push(x);
        }
        int p = s2.top();
        // s2.pop();
        return p;
        
    }
    
    bool empty() {
        return s1.empty()&&s2.empty();
    }
};
