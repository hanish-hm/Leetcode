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
    void recursion(TreeNode* root,int x,vector<int>& ans){
        if(root == NULL){
            return;
        }
        if(x == ans.size()){
            ans.push_back(root->val);
        }
        if(root->right){
            recursion(root->right,x+1,ans);
        }
        if(root->left){
            recursion(root->left,x+1,ans);
        }
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        recursion(root,0,ans);
        return ans;
    }
};