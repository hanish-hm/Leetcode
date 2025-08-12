class Solution {
public:
    void func(vector<int>& candidates, int target,vector<vector<int>>& ans,int sum, int index,vector<int> x){
        if(sum == target){
            ans.push_back(x);
            return;
        }
        if(index>=candidates.size() || sum >target){
            return;
        }
        
        func(candidates,target,ans,sum,index+1,x);
        x.push_back(candidates[index]);
        func(candidates,target,ans,sum+candidates[index],index,x);
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        func(candidates,target,ans,0,0,{});
        return ans;
    }
};