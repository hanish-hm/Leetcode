class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int bit=0;bit<32;bit++){
            int onecount=0,zerocount=0;
            for(int j=0;j<n;j++){
                if(nums[j] & (1<<bit)){
                    onecount++;
                }
                else{
                    zerocount++;
                }
            }
            sum += onecount*zerocount;
        }
        
        return sum;
    }
};