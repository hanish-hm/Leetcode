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
        int mi = 0;
        int ma = 0;
        for(int i=0;i<n;i++){
            if(s[i] == '('){
                mi += 1;
                ma += 1;
            }
            else if(s[i] == ')'){
                mi -= 1;
                ma -= 1;
            }
            else{
                mi -= 1;
                ma += 1;
            }
            if(ma<0){
                return false;
            }
            if(mi<0){
                mi = 0;
            }
        }
        return mi==0;
    }
};