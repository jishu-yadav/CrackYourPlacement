// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	    vector<string>permutations;
	    set<string>st;
	    void permute(string s ,int l,int r){
	        if(l==r){
	            st.insert(s);
	        }
	        else
	        for(int i=l;i<=r;i++){
	            swap(s[l],s[i]);
	            permute(s,l+1,r);
	            swap(s[l],s[i]);
	        }
	    }
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    permute(S,0,S.size()-1);
		    for(auto &i:st){
		        permutations.push_back(i);
		    }
		    sort(permutations.begin(),permutations.end());
		    return permutations;
		    
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends