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
    int maxDepth(TreeNode* root){
        if(!root)
            return 0;
        int lmax = maxDepth(root->left);
        int rmax = maxDepth(root->right);
        return 1 + max(lmax,rmax);
    }
    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        if( abs(maxDepth(root->left) - maxDepth(root->right)) >1)
            return false;
        int l = maxDepth(root->left);
        int r = maxDepth(root->right);
        return isBalanced(root->left)&&isBalanced(root->right);
    }
};