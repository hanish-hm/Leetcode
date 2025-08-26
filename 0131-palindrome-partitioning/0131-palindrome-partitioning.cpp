class Solution {
public:
    bool ispalindrome(int start,int end,string s){
        while(start<=end){
            if(s[start]!=s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    void solve(vector<vector<string>>& ans,string& s,int index,int n,vector<string>& x){
        if(index==n){
            ans.push_back(x);
            return;
        }
        for(int i=index;i<n;i++){
            if(ispalindrome(index,i,s)){
                x.push_back(s.substr(index,i-index+1));
                solve(ans,s,i+1,n,x);
                x.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> x;
        int n = s.size();
        solve(ans,s,0,n,x);
        return ans;
    }
};