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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
//         stack<TreeNode*>stk1;
//         stack<TreeNode*>stk2;
        
//         vector<vector<int>>ans;
//         stk1.push(root);
        
//         while(stk2.empty()){
//             ans.push_back(root->val);
            
            
//         }
        vector<vector<int>>result;
        if(root==NULL)
            return result;
        queue<TreeNode*>nodesQueue;
        nodesQueue.push(root);
        bool leftToRight = true;
        while(!nodesQueue.empty()){
            int size = nodesQueue.size();
            vector<int>row(size);
            for(int i=0;i<size;i++){
                TreeNode* node = nodesQueue.front();
                nodesQueue.pop();
                int index = leftToRight ? i:size-1-i;
                row[index] = node->val;
                if(node->left)
                    nodesQueue.push(node->left);
                if(node->right)
                    nodesQueue.push(node->right);
                
            }
            leftToRight = !leftToRight;
            result.push_back(row);
            
        }
        return result;
    }
};