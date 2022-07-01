class Solution {
public:
    static bool cmp(const vector<int>&a,const vector<int>&b){
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int s=0;
        int c = 0;
        int n = boxTypes.size();
        sort(boxTypes.begin(),boxTypes.end(),cmp);
        for(int i=0;i<n;i++){
            int k = boxTypes[i][0];
            while(c<truckSize && k){
                s+=boxTypes[i][1];
                c++;
                k--;
            }
        }
        return s;
    }
};