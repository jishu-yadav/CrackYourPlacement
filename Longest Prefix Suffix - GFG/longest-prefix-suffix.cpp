// { Driver Code Starts
//Initial template for C++ 
 
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

//User function template for C++

class Solution{
  public:		
	int lps(string s) {
	    // Your code goes here
	    int n = s.size();
	    string s1="";
	    string s2="";
	    int i =n-1,j=1;
	    while(i>0 and j<n-1){
	        if(s[0]!=s[j]){
	            i--;
	            j++;
	            continue;
	        }
	        s1 = s.substr(0,i);
	        s2 = s.substr(j,n);
	        if(s1==s2) return s1.size();
	        j++;
	        i--;
	    }
	    if(s[0]==s[n-1]) return 1;
	    return 0;
	}
};

// { Driver Code Starts.

int main() 
{
   

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;

   		Solution ob;

   		cout << ob.lps(str) << "\n";
   	}

    return 0;
}
  // } Driver Code Ends