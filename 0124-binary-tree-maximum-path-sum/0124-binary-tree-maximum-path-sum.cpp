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
    int maxi = INT_MIN;
    int func(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int ls = max(func(root->left),0);
        int rs = max(func(root->right),0);
        int x = root->val+ls+rs;
        maxi = max(maxi,x);
        return root->val+max(ls,rs);
    }
    int maxPathSum(TreeNode* root) {
        func(root);
        return maxi;
    }
};