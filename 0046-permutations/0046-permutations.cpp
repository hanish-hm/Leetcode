class Solution {
public:
    void func(unordered_map<int,int> mp,vector<int> x,int n,vector<vector<int>>& ans,vector<int> nums){
        if(x.size() == n){
            ans.push_back(x);
            return;
        }
        for(int i=0;i<n;i++){
            if(!mp[i]){
                x.push_back(nums[i]);
                mp[i] = 1;
                func(mp,x,n,ans,nums);
                mp[i] = 0;
                x.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        unordered_map<int,int> mp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            mp[i] = 0;
        }
        func(mp,{},n,ans,nums);
        return ans;
    }
};