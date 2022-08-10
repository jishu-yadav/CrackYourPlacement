/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        if(n==0)
            return NULL;
        TreeNode* rootNode = new TreeNode(nums[n/2]);
        vector<int>left(nums.begin(),nums.begin()+n/2);
        vector<int>right(nums.begin()+n/2+1,nums.end());
        
        rootNode->left = sortedArrayToBST(left);
        rootNode->right = sortedArrayToBST(right);
        // TreeNode* node = new TreeNode(nums[0]);
        // for(int i=1;i<n;i++){
        //     if(nums[i]<node->val){
        //         node->left = new TreeNode(nums[i]);
        //     }else{
        //         node->right = new TreeNode(nums[i]);
        //     }
        // }
        
        return rootNode;
    }
};