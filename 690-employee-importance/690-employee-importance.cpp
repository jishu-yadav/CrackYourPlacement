/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int,Employee*>mp;
        for(auto i:employees) mp[i->id] = i;
        int sum = 0;
        deque<Employee*>q;
        q.push_back(mp[id]);
        while(!q.empty()){
            auto p = q.front();
            q.pop_front();
            for(auto x:p->subordinates){
                q.push_back(mp[x]);
            }
             sum+=p->importance;
        }
        return sum;
    }
};