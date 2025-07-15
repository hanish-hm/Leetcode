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
    TreeNode* insertIntoBST(TreeNode* root, int val) {

        if(root==NULL){
            return new TreeNode(val);
        }
        TreeNode* roo = root;
        TreeNode* node;
        int a;
        while(root){
            
            if(val<root->val){
                node = root;
                a=1;
                root = root->left;
            }
            else{
                a=2;
                node = root;
                root = root->right;
            }
        }
        if(root==NULL){
                TreeNode* newnode = new TreeNode(val);
                if(a==1){
                    node->left = newnode;
                }
                else{
                    node->right = newnode;
                }
            }
        return roo;
    }
};