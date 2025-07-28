class Solution {
public:
    void func(int i,int n,vector<int> vec,vector<int>& nums,vector<vector<int>>& ans){
        if(i>=n){
            ans.push_back(vec);
            return;
        }
        func(i+1,n,vec,nums,ans);
        vec.push_back(nums[i]);
        func(i+1,n,vec,nums,ans);
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        func(0,n,{},nums,ans);
        return ans;
    }
};