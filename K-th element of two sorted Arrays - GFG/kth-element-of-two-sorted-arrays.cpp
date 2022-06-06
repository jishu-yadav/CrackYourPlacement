// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int m, int n, int k)
    {
        long long int p1 = 0,p2 = 0,counter =0,answer=0;
        while(p1<m && p2<n){
            if(counter == k) break;
            else if(arr1[p1]<arr2[p2]){
                answer = arr1[p1];
                ++p1;
            }else{
                answer = arr2[p2];
                ++p2;
            }
            ++counter;
        }
        if(counter!=k){
            if(p1!=m){
                answer = arr1[p1+k-counter-1];
            }else
            answer = arr2[p2+k-counter-1];
        }
        return answer;
    }
};

// { Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}  // } Driver Code Ends