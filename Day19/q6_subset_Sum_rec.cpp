// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    void subSum(int i,int sum,vector<int>arr,int n,vector<int>&ans){
        if(i==n){
            ans.push_back(sum);
            return;
        }
        subSum(i+1,sum+arr[i],arr,n,ans);//take element
        subSum(i+1,sum,arr,n,ans);//not take ele
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int>ans;
        int sum=0;
        subSum(0,sum,arr,N,ans);
        return ans;
        
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } //subset sum using recursion
