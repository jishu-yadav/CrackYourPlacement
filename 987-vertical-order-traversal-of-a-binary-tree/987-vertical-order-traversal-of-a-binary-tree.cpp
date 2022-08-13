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
   
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int,int >>>mp; // col - row - val
        queue<pair<TreeNode*,pair<int,int> >>q; // val, row ,col number
        q.push({root,{0,0}});
        
        while(!q.empty()){
            TreeNode* curNode = q.front().first;
            //int curVal = q.front().first;
            int rowNumber = q.front().second.first;
            int colNumber = q.front().second.second;
            q.pop();
            mp[colNumber].push_back({rowNumber,curNode->val});
            if(curNode->left!=NULL){
                q.push({curNode->left,{rowNumber+1,colNumber-1}});
            }
            if(curNode->right!=NULL){
                q.push({curNode->right,{rowNumber+1,colNumber+1}});
            }
        }
        vector<vector<int>>ans;
        for(auto i:mp){
            sort(i.second.begin(),i.second.end());
            vector<int>tmp;
            for(auto ele:i.second){
                tmp.push_back(ele.second);
            }
            ans.push_back(tmp);
        }
        
        return ans;
    }
};