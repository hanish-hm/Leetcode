class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int maxx = -1;
        int x;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]<nums[j]){
                    x = nums[j] - nums[i];
                    maxx = max(maxx,x);
                }
            }
        }
        return maxx;
    }
};