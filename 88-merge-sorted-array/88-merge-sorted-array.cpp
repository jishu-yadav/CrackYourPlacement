class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int x=m+n-1;
        // for(int i=m;i<m+n;i++){
        //     nums1[i] = nums2[x++];
        // }
        // sort(nums1.begin(),nums1.end());   
        int idx1=m-1;
        int idx2=n-1;
        while(idx1>=0 && idx2>=0){
            if(nums1[idx1]<nums2[idx2]){
                nums1[x--] = nums2[idx2--];
            }
            else{
                nums1[x--] = nums1[idx1--];
            }
        }
//         while(idx1>=0){
//             if(nums1[idx1]<nums2[idx2]){
//                 nums1[x--] = nums2[idx2--];
//             }
//             else{
//                 nums1[x--] = nums1[idx1--];
//             }
//         }
        
        while(idx2>=0){
            nums1[x--]=nums2[idx2--];
            // if(nums1[idx1]<nums2[idx2]){
            //     nums1[x--] = nums2[idx2--];
            // }
            // else{
            //     nums1[x--] = nums1[idx1--];
            // }
        }
        
    }
};