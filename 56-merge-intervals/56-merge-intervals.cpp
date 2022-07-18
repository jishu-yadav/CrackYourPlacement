class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        vector<vector<int>>res;
        int n= intervals.size();
        if(n==0){
            return res;
        }
        sort(intervals.begin(),intervals.end());
        int a1 = intervals[0][0], a2 = intervals[0][1];
        for(int i=1;i<n;i++){
            if(intervals[i][0]>a2){
                res.push_back({a1,a2});
                a1 = intervals[i][0];
                a2 = intervals[i][1];
            }else if(intervals[i][1]>a2){
                a2 = intervals[i][1];
            }
        }
        res.push_back({a1,a2});
        
        
        
        
        //or
//      vector<int>tempI = intervals[0];
//      for(auto i:intervals){
//          if(i[0]<=tempI[1]){
//              tempI[1] = max(tempI[1],i[1]);
             
//          }
//          else{
//              mergedIntervals.push_back(tempI);
//              tempI= i;
//          }
//      }
        //mergedIntervals.push_back(tempI);
        
        
//         vector<vector<int>>res;
//         sort(intervals.begin(),intervals.end());
//         int a1=intervals[0][0],a2=intervals[0][1];
//         for(int i=1;i<intervals.size();i++){
//             if(intervals[i][0]>a2){
//                 res.push_back({a1,a2});
//                 a1=intervals[i][0];
//                 a2=intervals[i][1];
//             }            
//             else if(intervals[i][1]>a2){
//                 a2=intervals[i][1];
//             }
            
//         }
//         res.push_back({a1,a2});
        return res;
//       return mergedIntervals;
        
    }
};