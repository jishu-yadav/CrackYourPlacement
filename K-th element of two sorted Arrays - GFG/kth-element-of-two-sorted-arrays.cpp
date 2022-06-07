// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int m, int n, int k,int st1 = 0, int st2 = 0)
    {
        // IN THIS QS node the increment of p1
        // long long int p1 = 0,p2 = 0,counter =0,answer=0;
        // while(p1<m && p2<n){
        //     if(counter == k) break;
        //     else if(arr1[p1]<arr2[p2]){
        //         answer = arr1[p1];
        //         ++p1;
        //     }else{
        //         answer = arr2[p2];
        //         ++p2;
        //     }
        //     ++counter;
        // }
        // if(counter!=k){
        //     if(p1!=m){
        //         answer = arr1[p1+k-counter-1];
        //     }else
        //     answer = arr2[p2+k-counter-1];
        // }
        // return answer;
        
        // above soln is O(1)
        // another approach
        
        
        /// below appraoch is by striver understop=od but given wa check once more
    //     if(m > n) {
    //     return kthElement(arr2, arr1, n, m, k); 
    // }
        
    // int low = max(0,k-m), high = min(k,n);
        
    // while(low <= high) {
    //     int cut1 = (low + high) >> 1; 
    //     int cut2 = k - cut1; 
    //     int l1 = cut1 == 0 ? INT_MIN : arr1[cut1 - 1]; 
    //     int l2 = cut2 == 0 ? INT_MIN : arr2[cut2 - 1];
    //     int r1 = cut1 == n ? INT_MAX : arr1[cut1]; 
    //     int r2 = cut2 == m ? INT_MAX : arr2[cut2]; 
            
    //     if(l1 <= r2 && l2 <= r1) {
    //         return max(l1, l2);
    //     }
    //     else if (l1 > r2) {
    //         high = cut1 - 1;
    //     }
    //     else {
    //         low = cut1 + 1; 
    //     }
    // }
    // return 1; 
    
    
    // In case we have reached end of array 1
    if (st1 == m)
        return arr2[st2 + k - 1];
 
    // In case we have reached end of array 2
    if (st2 == n)
        return arr1[st1 + k - 1];
 
    // k should never reach 0 or exceed sizes
    // of arrays
    if (k == 0 || k > (m - st1) + (n - st2))
        return -1;
 
    // Compare first elements of arrays and return
    if (k == 1)
        return (arr1[st1] < arr2[st2]) ?
            arr1[st1] : arr2[st2];
    int curr = k / 2;
 
    // Size of array 1 is less than k / 2
    if (curr - 1 >= m - st1)
    {
        // Last element of array 1 is not kth
        // We can directly return the (k - m)th
        // element in array 2
        if (arr1[m - 1] < arr2[st2 + curr - 1])
            return arr2[st2 + (k - (m - st1) - 1)];
        else
            return kthElement(arr1, arr2, m, n, k - curr,
                st1, st2 + curr);
    }
 
    // Size of array 2 is less than k / 2
    if (curr-1 >= n-st2)
    {
        if (arr2[n - 1] < arr1[st1 + curr - 1])
            return arr1[st1 + (k - (n - st2) - 1)];
        else
            return kthElement(arr1, arr2, m, n, k - curr,
                st1 + curr, st2);
    }
    else
    {
        // Normal comparison, move starting index
        // of one array k / 2 to the right
        if (arr1[curr + st1 - 1] < arr2[curr + st2 - 1])
            return kthElement(arr1, arr2, m, n, k - curr,
                st1 + curr, st2);
        else
            return kthElement(arr1, arr2, m, n, k - curr,
                st1, st2 + curr);
    }
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