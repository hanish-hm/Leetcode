class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            int count = 0;
            int newsum = 0;
            for(int j=1;j*j<=nums[i];j++){
                if(nums[i]%j==0){
                    newsum+=j;
                    count++;
                    if(nums[i]/j != j){
                        newsum+=nums[i]/j;
                        count++;
                    }
                }
            }
            if(count==4){
                sum+=newsum;
            }
        }
        return sum;
    }
};