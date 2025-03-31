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
    public: int sumNumbers(TreeNode* root) {
        return helper(root, 0);
    }
    private: int helper(TreeNode* node , int sum){
        if(node==NULL)
        return 0;

        sum=sum*10 + node->val;

        if(node->left == NULL && node->right==NULL)
        return sum;

        return helper(node->left , sum) + helper(node->right , sum);
    }
};