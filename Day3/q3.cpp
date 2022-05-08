class NestedIterator {
stack<int>stk;
public:
   
    NestedIterator(vector<NestedInteger> &nestedList) {
        dfs(nestedList);
        
    }
    void dfs(vector<NestedInteger> &nestedList){
        for(int i=nestedList.size()-1;i>=0;i--){
            if(nestedList[i].isInteger()) stk.push(nestedList[i].getInteger());
            else{
                dfs(nestedList[i].getList());
            }
        }
    }
    int next() {
        // if(!stk.empty())
        int next = stk.top();
        stk.pop();
        return next;
            
    }
    
    bool hasNext() {
        return !stk.empty();
    }
};
//flatten list
