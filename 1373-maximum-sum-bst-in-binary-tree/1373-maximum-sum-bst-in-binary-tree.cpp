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
// class Solution {
// public:
//     int maxLeft = INT_MIN;
//     int minRight = INT_MAX;
//     int mx = INT_MIN;
//     vector<int> sumBSTCheck(TreeNode* root){// sum,isBST,maxLeft,minRight;
//         vector<int>values(4);
        
//         if(root==NULL){
//             mx = max(mx,0);
//             return {0,1,INT_MIN,INT_MAX};
//         }
//         if(root->left==NULL && root->right==NULL){
//             mx = max(root->val,mx);
//             return {root->val,1,root->val,root->val};
//         }
//         vector<int>left;
//         vector<int>right;
//         if(root->left){
//             left = sumBSTCheck(root->left);
//             //cout<< maxLeft<<" ";
//             //maxLeft = max(maxLeft, max(left[2],right[2]));
            
//         } 
//         if(root->right){
//            //cout<< minRight<<" ";
//            right = sumBSTCheck(root->right);   
//            //minRight = min(minRight, min(left[3],right[3]));
//         }
//         maxLeft = max(root->val, max(left[2],right[2]));
//         minRight = min(root->val, min(left[3],right[3]));
//         cout << maxLeft << "\n";
//         cout << minRight << "\n";
//         if(left[1]==1 && right[1]== 1){
            
//             if( (root->val > maxLeft) && (root->val < minRight) )
//             {
//                 mx = max(mx ,root->val + right[0] +left[0]);
//                 cout<< root->val + right[0] + left[0]<<" ";
                
//                 return {root->val + right[0] +left[0],1 ,maxLeft,minRight} ;
//             }
//             else{
//                 //cout<< root->val + right[0] + left[0]<<" ";
//                 return {root->val + right[0] +left[0], 0,maxLeft,minRight};
//             }
//         }
//         else{
//                 //cout<< root->val + right[0] + left[0]<<" ";
//                 return {  root->val + right[0] + left[0], 0, maxLeft,minRight};
//         }
        
//     } 
//     int maxSumBST(TreeNode* root) {
        
//         vector<int>vec = sumBSTCheck(root);
//         return mx; 
//     }
// };
int ans;
class prop{
public:
    bool bst;       //to check if tree is bst
    int ma;         //max value in a tree
    int mi;         //min value in an tree
    int ms;         //current maximum sum
    prop(){
        bst=true;
        ma=INT_MIN;
        mi=INT_MAX;
        ms=0;
    }
};
class Solution {
public:
    prop calcSum(TreeNode* root){
        if (root == NULL){
            return prop();
        }
        prop p;
        prop pl = calcSum(root->left);                        //recursive call for left sub-tree
        prop pr = calcSum(root->right);                       //recursive call for right sub-tree
		
		//if sub-tree including this node is bst
        if ( pl.bst==true && pr.bst==true && root->val>pl.ma && root->val<pr.mi ){
            p.bst = true;                                                      //current tree is a bst
            p.ms = pl.ms + pr.ms + root->val;          
            p.mi  = min(root->val, pl.mi);
            p.ma = max(root->val, pr.ma);
        }
		//if current tree is not a bst
        else {
            p.bst=false;
            p.ms=max(pl.ms, pr.ms);
        }
		
        ans=max(ans, p.ms);
        return p;
    }
    int maxSumBST(TreeNode* root){
        ans = 0;
        calcSum(root);
        return ans;
    }
};