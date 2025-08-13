class Solution {
public:
    void func(vector<int>& candidates, int target,vector<vector<int>>& ans,int index,int sum,vector<int> x){
        if(sum == target){
            ans.push_back(x);
            return;
        }
        if(index>=candidates.size() || sum>target){
            return;
        }
        x.push_back(candidates[index]);
        func(candidates,target,ans,index+1,sum+candidates[index],x);
        x.pop_back();
        int nextIndex = index + 1;
        while (nextIndex < candidates.size() && candidates[nextIndex] ==    candidates[index]) {
            nextIndex++;
        }
        func(candidates, target, ans, nextIndex, sum, x);
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        sort(candidates.begin(),candidates.end());
        func(candidates,target,ans,0,0,{});
        sort(ans.begin(),ans.end());
        return ans;
    }
};