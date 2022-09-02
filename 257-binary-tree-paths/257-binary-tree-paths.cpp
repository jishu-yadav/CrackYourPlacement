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
    void helper(TreeNode* root,string path,vector<string>&paths){
        path+=to_string(root->val);
        if(root->left==NULL && root->right==NULL){
            paths.push_back(path);
            return;
        }
        if(root->left)
            helper(root->left,path+"->",paths);
        if(root->right)
            helper(root->right,path+"->",paths);
        
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>paths;
        if(root==NULL)
            return paths;
        helper(root,"",paths);
        return paths;
    }
};