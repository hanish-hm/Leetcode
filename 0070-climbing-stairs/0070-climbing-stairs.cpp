class Solution {
public:
    int func(int n,vector<int>& dp){
        if(dp[n] != -1){
            return dp[n];
        }
        return dp[n] = func(n-1,dp)+func(n-2,dp);
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        dp[0] = 1;
        dp[1] = 1;
        return func(n,dp);
    }
};
