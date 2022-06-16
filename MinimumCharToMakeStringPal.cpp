bool pal(string s){
    int i=0,j=s.size()-1;
    while(i<=j){
        if(s[i++]!=s[j--]){
            return false;
        }
    }
    return true;
}
int Solution::solve(string A) {
    int n = A.size();
    int cnt=0;
    int flag=0;
    while(A.size()>0){
        if(pal(A)){
            flag = 1;
            break;
        }
        else
        {
        cnt++;
        A.erase(A.begin()+A.size()-1);    
        }
    }
    if(flag)
    return cnt;
    
    return -1;
    
}
//tle giving brute force solution
