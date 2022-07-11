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
    vector<int>rightView;
    void rightUtil(TreeNode* root,int level,int *max_level){
        if(root==NULL)
            return;
        if(*max_level<level){
            rightView.push_back(root->val);
            *max_level = level;
        }
        rightUtil(root->right , level+1 ,max_level);
        rightUtil(root->left , level+1 ,max_level);
            
    }
    vector<int> rightSideView(TreeNode* root) {
        int max_level =0;
        rightUtil(root,1,&max_level);
        return rightView;
    }
};