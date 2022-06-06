// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:

	int NthRoot(int n, int m)
	{
	    // Code here.
	    long int  ans = 0;
	    long int element = 0;
	    while(element<=m){
	        element = pow(ans,n);
	        if(element == m){
	            return ans;
	        }
	        ans++;
	    }
	    return -1;
	}  
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}  // } Driver Code Ends