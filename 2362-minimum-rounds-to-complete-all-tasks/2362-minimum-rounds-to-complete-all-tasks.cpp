class Solution {
public:
    int fn(int freq,vector<int>& dp){
        if(freq == 0){
            return 0;
        }
        if(freq<0){
            return 1e9;
        }
        if(dp[freq]!=-1){
            return dp[freq];
        }
        int x = 1+fn(freq-2,dp);
        int y = 1+fn(freq-3,dp);
        return dp[freq]=min(x,y);
    }
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> mp;
        int maxfreq = 0;
        for(int t:tasks){
            mp[t]++;
            maxfreq = max(maxfreq,mp[t]);
        }
        int ans = 0;
        vector<int> dp(maxfreq+1,-1);
        for(auto [num,freq]:mp){
            int total=fn(freq,dp);
            if(total>=1e9){
                return -1;
            }
            ans+=total;
        }
        return ans;
    }
};