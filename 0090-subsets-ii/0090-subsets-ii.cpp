class Solution {
public:
    void func(vector<int>& nums,int index,set<vector<int>>& st,vector<int> x){
        if(index>=nums.size()){
            st.insert(x);
            return;
        }
        x.push_back(nums[index]);
        func(nums,index+1,st,x);
        x.pop_back();
        int nxt = index+1;
        
        func(nums,nxt,st,x);
        return;
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> st;
        sort(nums.begin(),nums.end());
        func(nums,0,st,{});
        vector<vector<int>> ans;
        for(auto it:st){
            ans.push_back(it);
        }
        return ans;
    }
};