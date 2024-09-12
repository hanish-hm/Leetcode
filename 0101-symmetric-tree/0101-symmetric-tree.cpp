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
    bool check(TreeNode* l,TreeNode* r){
        if(!l && !r){
            return true;
        }
        if (!l || !r || l->val != r->val) return false;
        if(l->val != r->val){
            return false;
        }
        bool lef = check(l->left,r->right);
        bool righ = check(l->right,r->left);
        return lef && righ;
    }

    bool isSymmetric(TreeNode* root) {
        bool ans = check(root->left,root->right);
        return ans;
    }
};