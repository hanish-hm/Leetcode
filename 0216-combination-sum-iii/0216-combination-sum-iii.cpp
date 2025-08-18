class Solution {
public:
    void fn(vector<vector<int>>& ans,int k,int n,vector<int>& x,int sum,int index){
        if(sum > n || x.size()>k){
            return;
        }
        if(sum == n && x.size() == k){
            ans.push_back(x);
            return;
        }
        for(int i=index;i<10;i++){
            x.push_back(i);
            fn(ans,k,n,x,sum+i,i+1);
            x.pop_back();           
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> x;
        fn(ans,k,n,x,0,1);
        return ans;
    }
};