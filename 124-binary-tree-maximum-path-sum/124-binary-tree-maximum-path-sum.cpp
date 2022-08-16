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
    int solve(TreeNode* root,int &res)
    {
        // Base Case 
        if(root==NULL) return NULL;
        int ls = solve(root->left,res);
        int rs = solve(root->right,res);
//         int temp = max(max(ls,rs)+root->val, root->val);
//         int ans = max(temp, ls+rs+root->val);
       
       
//         res = max(res,ans);
        ls = max(0,ls);
        rs = max(0,rs);
        int choice1 = ls+rs+root->val;
        //int choice2 = root->val;
        res = max(res, ls+rs+root->val);
        return max(ls,rs)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        solve(root,res);
        return res;
    }
};