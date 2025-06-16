class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        vector<vector<int>> ans;
        vector<int> merge = intervals[0];
        for(int i=0;i<n;i++){
            if(merge[1]<intervals[i][0]){
                ans.push_back(merge);
                merge = intervals[i];
            }
            else{
                merge[0] = min(merge[0],intervals[i][0]);
                merge[1] = max(merge[1],intervals[i][1]);
            }
        }
        ans.push_back(merge);
        return ans;
    }
};