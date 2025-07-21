class Solution {
public:
    bool isprime(int n){
        if(n==1){
            return false;
        }
        for(int i=2;i<=sqrt(n);i++){
            if(n%i==0){
                return false;
            }
        }
        return true;
    }
    int maximumPrimeDifference(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n-1;
        int minindex = 0;
        int maxindex = 0;
        for(int i=0;i<n;i++){
            if(isprime(nums[i])){
                minindex = i;
                break;
            }
        }
        for(int i=n-1;i>=minindex;i--){
            if(isprime(nums[i])){
                maxindex = i;
                break;
            }
        }
        return maxindex-minindex;
    }
};