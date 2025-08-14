class Solution {
public:
    void func(vector<int>& nums,int index,vector<vector<int>>& ans,vector<int> x){
        if(index>=nums.size()){
            ans.push_back(x);
            return;
        }
        x.push_back(nums[index]);
        func(nums,index+1,ans,x);
        x.pop_back();
        int nxt = index+1;
        while(nxt<nums.size() && nums[nxt]==nums[index]){
            nxt++;
        }
        func(nums,nxt,ans,x);
        return;
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        func(nums,0,ans,{});
        
        return ans;
    }
};