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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        map<int,TreeNode*> mp;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->left){
                q.push(node->left);
                mp[node->left->val] = node;
            }
            if(node->right){
                q.push(node->right);
                mp[node->right->val] = node;
            }
        }
        q.push(target);
        map<TreeNode*,int> vis;
        vis[target] = 1;
        int a = 0;
        while(!q.empty()){
            if(k == a){
                break;
            }
            int n = q.size();
            for(int i = 0; i< n;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left && !vis[node->left]){
                    q.push(node->left);
                    vis[node->left] = 1;
                }
                if(node->right && !vis[node->right]){
                    q.push(node->right);
                    vis[node->right] = 1;
                }
                if(mp[node->val] && !vis[mp[node->val]]){
                    q.push(mp[node->val]);
                    vis[mp[node->val]] = 1;
                }
            }
            a++;
        }
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};