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
    TreeNode* build(int& i,vector<int>& preorder,int upperbound){
        if(i==preorder.size() || upperbound<preorder[i]){
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[i++]);  
        root->left = build(i,preorder,root->val);
        root->right = build(i,preorder,upperbound);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return build(i,preorder,INT_MAX);  
    }
};