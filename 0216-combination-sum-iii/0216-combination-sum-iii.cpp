class Solution {
public:
    void fn(vector<vector<int>>& ans,unordered_map<int,int>& mp,int k,int n,vector<int>& x,int sum,int index){
        if(sum > n || x.size()>k){
            return;
        }
        if(sum == n && x.size() == k){
            ans.push_back(x);
            return;
        }
        for(int i=index;i<10;i++){
            if(!mp[i]){
                x.push_back(i);
                mp[i] = 1;
                fn(ans,mp,k,n,x,sum+i,i+1);
                mp[i] = 0;
                x.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        unordered_map<int,int> mp;
        for(int i=1;i<10;i++){
            mp[i] = 0;
        }
        vector<int> x;
        fn(ans,mp,k,n,x,0,1);
        return ans;
    }
};