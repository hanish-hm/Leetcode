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
    TreeNode* func(vector<int>& preorder,int prestart, int preend, vector<int>& inorder,int instart,int inend,unordered_map<int,int>& mp){
        if(prestart>preend || instart>inend){
            return NULL;
        }
        TreeNode* node = new TreeNode(preorder[prestart]);
        int prepositionininorder = mp[node->val];
        int left = prepositionininorder - instart;
        node->left = func(preorder,prestart+1,prestart+left,inorder,instart,prepositionininorder-1,mp);
        node->right = func(preorder,prestart+left+1,preend,inorder,prepositionininorder+1,inend,mp);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[inorder[i]] = i;
        }
        TreeNode* root = func(preorder,0,n-1,inorder,0,n-1,mp);
        return root;
    }
};