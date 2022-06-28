class Solution {
public:
    
    //: only 70 test cases passed :/
//     int minStickCost = 0;
//     int cutHelper(int start,int end,int idx,vector<int>&cuts,int cutsArrSize){
//         if(idx>cutsArrSize){
//             return 0; 
//         }
//         int cost = end-start;
//         int ans = INT_MAX;
//         for(int k=idx;k<=cutsArrSize;k++){
//             ans = min( 
//                 ans, 
//                 cutHelper(start,cuts[k],idx,cuts,k-1) + 
//                 cutHelper(cuts[k],end,k+1,cuts,cutsArrSize) 
//             );
//         }
//         cost+=ans;
//         //minStickCost += cost;
//         return cost;
        
//     }
    
    
    //Memoization : only 70 test cases passed :/
    
//     int dp[5000][4999];
//     int cutHelper(int start,int end,int idx,vector<int>&cuts,int cutsArrSize){
//         if(idx>cutsArrSize){
//             return 0; 
//         }
//         if(dp[start][end]!=-1)
//             return dp[start][end];
//         int cost = end-start;
//         int ans = INT_MAX;
//         for(int k=idx;k<=cutsArrSize;k++){
//             ans = min( 
//                 ans, 
//                 cutHelper(start,cuts[k],idx,cuts,k-1) + 
//                 cutHelper(cuts[k],end,k+1,cuts,cutsArrSize) 
//             );
//         }
//         cost+=ans;
//         return dp[start][end]=cost;
        
//     }
    
    int cutHelper(int start,int end,int idx,vector<int>&cuts,int cutsArrSize){
        //here end is 'n' and cuts is an array of cutting points..
        cuts.push_back(0);
        cuts.push_back(end);
        vector<vector<int>>dp( cutsArrSize, vector<int>(cutsArrSize,0));
        
       //memset(dp,-1,sizeof(dp)); 
       // for(int i=0;i<cutsArrSize;i++){
       //     for(int j=0;j<cutsArrSize;i++){
       //         if(i==j-1){
       //             dp[i][j] = 0;
       //         }
       //     }
       // }
        for(int i=cutsArrSize-1;i>=0;i--){
              for(int j=i+1;j<=cutsArrSize-1;j++){
                  if(i==j-1){
                      dp[i][j] = 0; // base case
                  }
                  else{
                    int ans = 1e9;//or 1e9
                    for(int k=i+1;k<j;k++){
                        
                        int currCost = cuts[j]-cuts[i]+dp[i][k]+dp[k][j]; 
                        //dp[i][j] = min(dp[i][k], dp[k][j] + (j-i)); // (j-i) 
                        ans = min(ans,currCost);
                    }  
                      dp[i][j] = ans;
                  }
              }
         }
    return dp[0][cutsArrSize-1];
    }  

    
//     int solve(int n, vector<int>& cuts)
//     {
//         int N = cuts.size();
//         sort(cuts.begin(),cuts.end());
//         int dp[n+1][N][N];
        
//         // Initializing the dp with some values
//         for(int i=0; i<N; i++)
//         {
//             for(int j=0; j<N; j++)
//             {
//                 dp[0][i][j] = INT_MAX;
//             }
//         }
        
//         for(int len=1; len<=n; len++)
//         {
//             for(int i=0; i<N; i++)
//             {
//                 for(int j=0; j<N; j++)
//                 {
//                     if(i > j)
//                         dp[len][i][j] = len;
//                     else
//                     {
//                         dp[len][i][j] = min(dp[len][i][j])
//                     }
//                 }
//             }
//         }
        
        
//     }
    // int solve(int n , vector<int>&cuts){
    //     int dp[101][1000001]
    // }
    int minCost(int n, vector<int>& cuts) {
        
        // sort(cuts.begin(),cuts.end());
        // // int rodLength = n;
    //int cutsArrSize = cuts.size();
        // int start = 0;
        // int end = n;
        // // memset(dp,-1,sizeof(dp));
        // // int ans = cutHelper(start,end,0,cuts,cutsArrSize-1);// for memoization use this
        // int ans = cutHelper(start,end,0,cuts,cutsArrSize);
        // return ans;
        
    cuts.push_back(0);
	cuts.push_back(n);
	int  cutsArrSize = cuts.size();
	sort(cuts.begin(), cuts.end());
	vector<vector < int>> dp( cutsArrSize, vector<int> ( cutsArrSize, 0));
	for (int i =  cutsArrSize - 1; i >= 0; i--)
	{
		for (int j = i + 1; j <=  cutsArrSize - 1; j++)
		{
			if (i == j - 1) dp[i][j] = 0;	// base case
			else
			{
				int ans = 1e9;
				for (int k = i + 1; k < j; k++)
				{
					int currcost = cuts[j] - cuts[i] + dp[i][k] + dp[k][j];
					ans = min(ans, currcost);
				}
				dp[i][j] = ans;
			}
		}
	}
	return dp[0][cutsArrSize - 1];
    }
};