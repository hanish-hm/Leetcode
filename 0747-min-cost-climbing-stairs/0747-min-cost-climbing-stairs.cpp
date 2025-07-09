class Solution {
public:
    int ans = 0;
    int func(int n,vector<int>& cost,vector<int>& dp){
        if(n<=1){
            return cost[n];
        }
        if(dp[n]!= -1){
            return dp[n];
        }
        return dp[n] = cost[n] + min(func(n-1,cost,dp),func(n-2,cost,dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n,-1);
        return min(func(n-1,cost,dp),func(n-2,cost,dp));
    }
};