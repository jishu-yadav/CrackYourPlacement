// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


 // } Driver Code Ends
//User function Template for C++


class Solution
{
    public:
    typedef pair<int,pair<int,int>>ppi;
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
    vector<int>output(K,0);
    priority_queue<ppi,vector<ppi>,greater<ppi>>pq;
    // Write your code here. 
    for(int i=0;i<arr.size();i++){
        pq.push({arr[i][0],{i,0}});
    }
    while(pq.empty()==false){
        ppi curr = pq.top();
        pq.pop();
        int i = curr.second.first;//array number
        int j = curr.second.second;//index in the array number i
        output.push_back(curr.first);
        if(j+1<arr[i].size())
            pq.push({arr[i][j+1], {i,j+1}});
    }
    output;
}
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}





  // } Driver Code Ends