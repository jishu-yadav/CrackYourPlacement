int Solution::solve(vector<int> &A, int B) {
    unordered_map<int,int>m;
    int x=0;
    int c=0;
    for(int i=0;i<A.size();i++){
        x=x^A[i];
        if(x==B)
        c++;
        int h = x^B;
        if(m.find(h)!=m.end()){
            c+=m[h];
        }
        
        m[x]++;
        
    }
    return c;
}

// subarray with given XOR 
