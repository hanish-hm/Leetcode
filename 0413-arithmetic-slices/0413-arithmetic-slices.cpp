class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n<3){
            return 0;
        }
        int ans = 0;
        int diff = nums[1]-nums[0];
        int i;
        int prev = 0;
        for(i=2;i<n;i++){
            if(nums[i]-nums[i-1]!=diff){
                int x = i-prev;
                ans+= (x-2)*(x-2+1)/2;
                diff = nums[i] - nums[i - 1];
                prev = i-1;
            }
        }
        int x = i-prev;
        if(x!=0){
            ans+= (x-2)*(x-2+1)/2;
        }
        return ans;
    }
};