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
    void findpar(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& par){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->left){
                q.push(node->left);
                par[node->left] = node;
            }
            if(node->right){
                q.push(node->right);
                par[node->right] = node;
            }
        }

    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> par;
        findpar(root,par);
        queue<TreeNode*> q;
        q.push(target);
        map<TreeNode*,bool> vis;
        vis[target] = true;
        int count = 0;
        while(!q.empty()){
            int n = q.size();
            if(count++==k){
                break;
            }
            for(int i=0;i<n;i++){
                TreeNode* node = q.front(); q.pop();
                if(node->left && !vis[node->left]){
                    q.push(node->left);
                    vis[node->left] = true;
                }
                if(node->right && !vis[node->right]){
                    q.push(node->right);
                    vis[node->right] = true;
                }
                if(par[node] && !vis[par[node]]){
                    q.push(par[node]);
                    vis[par[node]] = true;
                }
            }
        }
        vector<int> ans;
        while(!q.empty()){
            TreeNode* node = q.front();
            ans.push_back(node->val);
            q.pop();
        }
        return ans;
    }
};