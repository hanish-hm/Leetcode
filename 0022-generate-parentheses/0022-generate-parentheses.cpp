class Solution {
public:
    void func(int n,int index,vector<string>& ans,int count,int mxcount,string str){
        if(mxcount>n){
            return;
        }
        if(index>=n*2){
            ans.push_back(str);
            return;
        }
        func(n,index+1,ans,count+1,mxcount+1,str+"(");
        if(count>0){
            func(n,index+1,ans,count-1,mxcount,str+")");
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        func(n,0,ans,0,0,"");
        return ans;
    }
};