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
    bool isSimilar(TreeNode* root1,TreeNode* root2){
        
        if(!root1 || !root2 ){
            return root1==NULL&&root2==NULL;
        }
        else if(root1->val==root2->val )
            return isSimilar(root1->left,root2->left) && isSimilar(root1->right,root2->right);
        else
            return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root)
            return false;
        else if(isSimilar(root,subRoot))
            return true;
        else
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};