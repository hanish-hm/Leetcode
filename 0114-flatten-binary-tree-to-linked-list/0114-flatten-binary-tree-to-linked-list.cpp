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
    void pre(TreeNode* root,TreeNode*& x){
        if(root == NULL){
            return;
        }
        x->right = new TreeNode(root->val);
        x = x->right;
        pre(root->left,x);
        pre(root->right,x);
    }
    void flatten(TreeNode* root) {
        if (root == NULL) return;
        TreeNode* yee = new TreeNode(-1);
        TreeNode* x = yee;
        pre(root,x);
        root->left = NULL;
        root->right = yee->right->right;
    }
};