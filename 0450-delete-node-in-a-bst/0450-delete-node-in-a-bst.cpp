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
    TreeNode* finddeletenode(TreeNode* root,TreeNode*& parentofdeletenode,int key){
        if(root==NULL){
            return root;
        }
        if(root->val==key){
            return root;
        }
        parentofdeletenode =root;
        if(key<root->val){
            return finddeletenode(root->left,parentofdeletenode,key);
        }
        if(key>root->val){
            return finddeletenode(root->right,parentofdeletenode,key);
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL || (root->val==key && root->left==NULL && root->right==NULL)){
            return NULL;
        }
        int x = 0;
        if(key<root->val){
            x = 1;
        }
        if(key>root->val)
        {
            x = 2;
        }
        
        TreeNode* dummy = root;
        TreeNode* parentofdeletenode = NULL;
        TreeNode* deletenode = finddeletenode(dummy,parentofdeletenode,key);
        if(deletenode==NULL){
            return root;
        }
        
        TreeNode* leftofdeletenode = deletenode->left;
        TreeNode* rightofdeletenode = deletenode->right;
        if(deletenode==root){
            if(rightofdeletenode!=NULL){
                root = rightofdeletenode;
                while(rightofdeletenode->left!=NULL){
                    rightofdeletenode = rightofdeletenode->left;
                }
                rightofdeletenode->left = leftofdeletenode;

            }
            else{
                root = leftofdeletenode;
            }
            return root;
        }
        
        if (parentofdeletenode->left == deletenode) {
        if (leftofdeletenode != NULL) {
            parentofdeletenode->left = leftofdeletenode;
            TreeNode* temp = leftofdeletenode;
            while (temp->right != NULL) {
                temp = temp->right;
            }
            temp->right = rightofdeletenode;
        } else {
            parentofdeletenode->left = rightofdeletenode;
        }
    } else if (parentofdeletenode->right == deletenode) {
        if (rightofdeletenode != NULL) {
            parentofdeletenode->right = rightofdeletenode;
            TreeNode* temp = rightofdeletenode;
            while (temp->left != NULL) {
                temp = temp->left;
            }
            temp->left = leftofdeletenode;
        } else {
            parentofdeletenode->right = leftofdeletenode;
        }
    }
        return root;
    }
};