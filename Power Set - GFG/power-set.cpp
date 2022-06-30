// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	   vector<string>power_set;
	   
	   void findPowerSet(string &s, string &temp, int idx){
        if (idx >= s.size()) {
            if(temp!="")
                power_set.push_back(temp);
            return;
             
        }
         temp.push_back(s[idx]);
         findPowerSet(s, temp, idx+1);
         temp.pop_back();                   
         findPowerSet(s, temp, idx+1);
       }
     
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    string temp;
		    findPowerSet(s,temp,0);
		    sort(power_set.begin(),power_set.end());
		    return power_set;
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}  // } Driver Code Ends