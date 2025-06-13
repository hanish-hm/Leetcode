class Solution {
public:
    bool check(string s,int index,int count,vector<vector<int>>& dp){
        if(count<0){
            return false;
        }
        if(index == s.size()){
            return count==0;
        }
        if(dp[index][count] != -1){
            return dp[index][count];
        }
        if(s[index] == '('){
            return dp[index][count] = check(s,index+1,count+1,dp);
        }
        else if(s[index] == ')'){
            return dp[index][count] = check(s,index+1,count-1,dp);
        }
        return dp[index][count] = check(s,index+1,count+1,dp) || check(s,index+1,count-1,dp) || check(s,index+1,count,dp);
    }
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return check(s,0,0,dp);
    }
};