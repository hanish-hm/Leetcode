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
    TreeNode* func(vector<int>& postorder,int poststart, int postend, vector<int>& inorder, int instart, int inend, unordered_map<int,int>& mp){
        if(poststart>postend || instart>inend){
            return NULL;
        }
        TreeNode* root = new TreeNode(postorder[postend]);
        int betin = mp[root->val];
        int left  = betin-instart;
        root->left = func(postorder,poststart,poststart+left-1,inorder,instart,betin-1,mp);
        root->right = func(postorder,poststart+left,postend-1,inorder,betin+1,inend,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n= inorder.size()-1;
        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]] = i;
        }
        TreeNode* root = func(postorder,0,n,inorder,0,n,mp);
        return root;
    }
};