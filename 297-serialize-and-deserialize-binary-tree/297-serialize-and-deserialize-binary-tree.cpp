/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        queue<TreeNode*>q;
        if(!root) return "";
        q.push(root);
        while(!q.empty()){
            TreeNode* curNode = q.front();
            q.pop();
            if(curNode==NULL){
                s.append("#,");
            }else{
                s.append(to_string(curNode->val)+',');
            }
            if(curNode!=NULL){
                q.push(curNode->left);
                q.push(curNode->right);
            }
        }
        cout<<s<<" ";
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0)
            return NULL;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            getline(s,str,',');
            if(str=="#"){
                node->left=NULL;
            }else{
                TreeNode* leftnode = new TreeNode(stoi(str));
                node->left = leftnode;
                q.push(leftnode);
            }
            getline(s,str,',');
            if(str=="#"){
                node->right=NULL;
            }else{
                TreeNode*rightnode = new TreeNode(stoi(str));
                node->right = rightnode;
                q.push(rightnode);
            }
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));