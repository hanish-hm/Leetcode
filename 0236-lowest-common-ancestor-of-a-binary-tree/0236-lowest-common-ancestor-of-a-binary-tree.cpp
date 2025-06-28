/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* r) {

        queue<TreeNode*> q;
        q.push(root);
        unordered_map<int,TreeNode*> parent;
        while(!q.empty()){
            TreeNode* node= q.front();
            q.pop();
            if(node->left){
                q.push(node->left);
                parent[node->left->val] = node;
            }
            if(node->right){
                q.push(node->right);
                parent[node->right->val] = node;
            }
        }
        set<TreeNode*> st;
        while(p!=root){
            st.insert(p);
            p = parent[p->val];
        }
        while(r!=root){
            if(st.find(r) != st.end()){
                return r;
            }
            r = parent[r->val];
        }
        return root;
    }
};