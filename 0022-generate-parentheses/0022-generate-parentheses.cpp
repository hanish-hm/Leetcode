class Solution {
public:
    void generate(int n,int open,int close, vector<string>& ans,string s){
        if(open==n && close == n){
            ans.push_back(s);
            return;
        }
        if(open<n){
            generate(n,open+1,close,ans,s+'(');
        }
        if(close<open){
            generate(n,open,close+1,ans,s+')');
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generate(n,0,0,ans,"");
        return ans;
    }
};