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
    void func(TreeNode* root,map<int,int>& mp){
        if(root==NULL){
            return;
        }
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int x = q.front().second;
            q.pop();
            mp[x] = node->val;
            if(node->left){
                q.push({node->left,x+1});
            }
            if(node->right){
                q.push({node->right,x+1});
            }
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        map<int,int> mp;
        func(root,mp);
        vector<int> ans;
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};