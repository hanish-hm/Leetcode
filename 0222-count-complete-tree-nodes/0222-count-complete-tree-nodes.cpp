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
    int countNodes(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int lh = 0;
        int rh = 0;
        TreeNode* lft = root->left;
        TreeNode* ryt = root->right;
        while(lft){
            lh++;
            lft = lft->left;
        }
        while(ryt){
            rh++;
            ryt = ryt->right;
        }
        if(lh == rh){
            return (1<<lh+1)-1;
        }
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};