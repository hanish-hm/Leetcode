class Solution {
public:
    bool canJump(vector<int>& nums) {
        int canreach = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(canreach<i){
                return false;
            }
            canreach = max(canreach,i+nums[i]);
            if(canreach>=n-1){
                return true;
            }
        }
        return true;
    }
};