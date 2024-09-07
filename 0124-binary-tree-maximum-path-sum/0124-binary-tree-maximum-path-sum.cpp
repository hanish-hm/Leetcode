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
    int findmaxsum(int& mx,TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int leftsum = max(0,findmaxsum(mx,root->left));
        int rightsum = max(0,findmaxsum(mx,root->right));

        mx = max(mx,leftsum+rightsum+root->val);

        return root->val+ max(leftsum,rightsum);
    }


    int maxPathSum(TreeNode* root) {
        int mx = INT_MIN;
        findmaxsum(mx,root);
        return mx;
    }
};