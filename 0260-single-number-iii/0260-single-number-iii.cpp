class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-1;i++){
            if(nums[i]!= nums[i+1]){
                ans.push_back(nums[i]);
            }
            else{
                i++;
            }
        }
        if(nums[n-1] != nums[n-2]){
            ans.push_back(nums[n-1]);
        }
        return ans;
    }
};