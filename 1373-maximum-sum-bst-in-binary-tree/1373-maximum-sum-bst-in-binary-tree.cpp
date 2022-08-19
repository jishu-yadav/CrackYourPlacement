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
class prop{
public:
    bool bst;
    int mn;
    int mx;
    int sum;
    prop(){
        bst = true;
        mn = INT_MAX;
        mx = INT_MIN;
        sum = 0;
    }
};
class Solution {
public:
    int ans = 0;
    prop maxSumBST_helper(TreeNode* root) {
        prop p;
        if(!root)
        {
            return p;
        }
        
        prop pl = maxSumBST_helper(root->left);
        prop pr = maxSumBST_helper(root->right);
        
        if( root->val > pl.mx && root->val < pr.mn && pl.bst==true && pr.bst==true ){
            p.bst = true;
            p.sum = root->val + pl.sum + pr.sum; 
            p.mn = min(root->val , pl.mn);
            p.mx = max(root->val, pr.mx);
        }
        else{
            p.bst = false;
            p.mn = INT_MIN;
            p.mx = INT_MAX;
            p.sum = max(pl.sum, pr.sum);
        }
        ans = max(ans, p.sum);
        return p;
    }
    int maxSumBST(TreeNode* root) {
        
        maxSumBST_helper(root);
        return ans;
    }
};