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
    int func(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        return func(root->left) + func(root->right) + root->val;
    }
    int findTilt(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int a = func(root->left);
        int b = func(root->right);

        return abs(a-b)+findTilt(root->left)+findTilt(root->right);
    }
};