//,merge two sorted arrays
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int x =0;
        for(int i=m+n-1;i>=m;i--){
            nums1[i]=nums2[x++];
        }
        sort(nums1.begin(),nums1.end());
    }
};
