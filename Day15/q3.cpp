class Solution {
public:
    
    int height(TreeNode* root){
        if(!root)
            return 0;
        int left= height(root->left);
        int right = height(root->right);
        return max(left,right)+1;
    }
    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        if(abs(height(root->left) - height(root->right))>1) return false;
        bool isleftBalanced = isBalanced(root->left);
        bool isrightBalanced = isBalanced(root->right);
        return isleftBalanced && isrightBalanced;
        
    }
};// balanced binary tree
