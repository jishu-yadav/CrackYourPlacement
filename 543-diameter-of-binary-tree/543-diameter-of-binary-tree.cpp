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
    int mx = 0;
    int diameter(TreeNode* root){
        if(!root)
            return 0;
        int lmax = diameter(root->left);
        int rmax = diameter(root->right);
        mx = max(mx,lmax+rmax);
        return max(lmax,rmax)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        diameter(root);
        return mx;
    }
};