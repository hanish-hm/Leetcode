class Solution {
public:
    int fn(int x){
        int count = 0;
        while(x>0){
            x = x&(x-1);
            count++;
        }
        return count;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        map<int,vector<int>> mp;
        for(auto x: arr){
            int setbits = fn(x);
            mp[setbits].push_back(x);
        }
        vector<int> ans;
        for(auto it:mp){
            for(auto n : it.second){
                ans.push_back(n);
            }
        }
        return ans;
    }
};