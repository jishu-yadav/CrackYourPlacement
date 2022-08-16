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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>inMap;
        for(int i=0;i<inorder.size();i++){
            inMap[inorder[i]] = i;
        }
        TreeNode* root = constructTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,inMap);
        return root;
    }
    TreeNode * constructTree(vector<int>&preorder,int preStart,int preEnd,vector<int>&inorder,int inStart,int inEnd,map<int,int>&mp){
        if(preStart>preEnd || inEnd<inStart) return NULL;
      TreeNode* root = new TreeNode(preorder[preStart]);
        int elem = mp[root->val];
        int nElem = elem - inStart;
        
        root->left =constructTree(preorder,preStart+1,preStart+nElem,inorder,inStart,elem-1,mp);
        root->right = constructTree(preorder,preStart+nElem+1,preEnd,inorder,elem+1,inEnd,mp);
        return root;
    }
};