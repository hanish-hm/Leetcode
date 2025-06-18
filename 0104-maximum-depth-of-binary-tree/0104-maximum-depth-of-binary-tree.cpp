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
    int maxDepth(TreeNode* root) {
        if(root == NULL ){
            return 0;
        }
        int count = 1;
        int ans = find(root,count);
        return ans-1;
    }
};