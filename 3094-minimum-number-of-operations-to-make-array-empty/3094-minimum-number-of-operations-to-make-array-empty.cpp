class Solution {
public:
    int fn(int freq,vector<int>& dp){
        if(freq == 0){
            return 0;
        }
        if(freq<0){
            return 1e6;
        }
        if(dp[freq] != -1){
            return dp[freq];
        }
        int x = 1+fn(freq-2,dp);
        int y = 1+fn(freq-3,dp);
        return dp[freq] = min(x,y);
    }
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> mp;
        int maxfreq = 0;
        for(int it:nums){
            mp[it]++;
            maxfreq = max(maxfreq,mp[it]);
        }
        int ans = 0;
        vector<int> dp(maxfreq+1,-1);
        for(auto [num,freq]:mp){
            int x = fn(freq,dp);
            if(x>=1e6){
                return -1;
            }
            ans+=x;
        }
        return ans;
    }
};