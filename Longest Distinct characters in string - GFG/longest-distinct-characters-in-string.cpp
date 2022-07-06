// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int longestSubstrDistinctChars (string s)
{
    // your code here
    set<char>st;
    int l=0,len=INT_MIN;
    for(int r=0;r<s.size();r++){
        //st.insert(s[r]);
        if(st.find(s[r])!=st.end())
        while(st.find(s[r])!=st.end() && l<r){
            st.erase(s[l]);
            l++;
        }
        st.insert(s[r]);
        len = max(len,r-l+1);
    }
    return len;
}