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
int dfs(TreeNode* root,int maxi){
   if(!root) return 0;
   int res=0;
   if(root->val>=maxi){
    res=1;
   }
   else{
    res=0;
   }
   maxi=max(maxi,root->val);
   res+=dfs(root->left,maxi);
   res+=dfs(root->right,maxi);
   return res;

}
    int goodNodes(TreeNode* root) {
        
        return dfs(root,root->val);
    }
};