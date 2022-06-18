/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool pathToNode(TreeNode* root,vector<TreeNode*>&arr,int targetVal){
        if(!root)
            return false;
        arr.push_back(root);
        if(root->val==targetVal)
            return true;
        
        if(pathToNode(root->left,arr,targetVal) || pathToNode(root->right,arr,targetVal))
            return true;
        arr.pop_back();
        return false;
    }
    TreeNode* dfs(TreeNode* root,TreeNode* p,TreeNode* q){
        if(root==p || root==q || root==NULL)
            return root;
        TreeNode* p1 = dfs(root->left,p,q);
        TreeNode* p2 = dfs(root->right,p,q);
        
        if(p1 && p2)
            return root;
        return p1?p1:p2;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         vector<TreeNode*>pathP;
//         pathToNode(root,pathP,p->val);
        return dfs(root,p,q);
    }
    
    
    
    
    
    
    
    
    
    
    
    
//      TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         vector<TreeNode*>pathP;
//         pathToNode(root,pathP,p->val);
//         // pathToNode(root,pathQ,q->val);
        
//         int mn=0;
//         if(pathP.size() < pathQ.size())
//             mn = pathQ.size();
//         TreeNode* x=pathP[0];
//         //x->val = pathP[0]->val;
//         for(int i=1;i<mn;i++){
//             x = pathP[i-1];
//             if(pathP[i]->val !=pathQ[i]->val)
//             {
//                 break;
//             }
//         }
//         return x;
        
//     }
};