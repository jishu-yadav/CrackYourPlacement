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
      int getLevel(TreeNode* root,int x,int level,int& parent){
        if(root==NULL)
            return 0;
        
        if(root->val==x)
            return level;
        parent = root->val;
        int lvl = getLevel(root->left,x,level+1,parent);
        if(lvl!=0)
            return lvl;
        parent = root->val;
        return getLevel(root->right,x,level+1,parent);
    }
    // void getParent(TreeNode* root,int x){
    //     if(root==NULL)
    //         return;
    //     // if( (root->left && root->left==NULL) || (root->right) && root->right=NULL)
    //     //     return;
    //     //parent = root->val;
    //     if(root->val==x){
    //         cout<< parent;
    //     }
    //     else{
    //         getParent(root->left,x);
    //         getParent(root->right,x);
    //     }
    // }
    bool isCousins(TreeNode* root, int x, int y) {

        if(root==NULL) return false;
        int p1 = -1;
        int xlevel = getLevel(root,x,1,p1);
        int p2 = -1;
        int ylevel = getLevel(root,y,1,p2);
        
        cout<<xlevel<<" "<<p1<<" \n";
         cout<<ylevel<<" "<<p2<<" ";
        // cout<<xlevel<<" "<<getParent(root,x)<<" \n";
        //  cout<<ylevel<<" "<getParent(root,y)<<" ";
        
        if(xlevel==ylevel && p1!=p2)
            return true;
        else
            return false;
    }
};