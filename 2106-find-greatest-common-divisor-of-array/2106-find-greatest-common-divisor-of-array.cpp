class Solution {
public:
    int findGCD(vector<int>& nums) {
        int a=1000,b=0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            a = min(a,nums[i]);
            b = max(b,nums[i]);
        }
        while (a > 0) {
            int temp = a;
            a = b % a;
            b = temp;
        }
        return b;
    }
};