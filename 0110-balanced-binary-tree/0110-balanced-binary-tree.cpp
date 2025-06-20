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
int find(TreeNode* root,int count){
    if(root == NULL){
        return count;
    }
    int a = find(root->left,count+1);
    int b = find(root->right,count+1);
    return max(a,b);
}
    bool isBalanced(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        int lh = find(root->left,0);
        int rh = find(root->right,0);

        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);

        return (abs(lh-rh)<2) && left && right;
    }
};