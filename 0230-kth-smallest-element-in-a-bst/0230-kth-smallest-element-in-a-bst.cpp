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
    void findsmallest(TreeNode* root, int k,int& ans,int& finall)
    {
        if(root==NULL){
            return;
        }
        findsmallest(root->left,k,ans,finall);
        ans++;
        if(ans == k){
            finall = root->val;
        }
        findsmallest(root->right,k,ans,finall);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;
        int finall;
        findsmallest(root,k,ans,finall);
        return finall;
    }
};