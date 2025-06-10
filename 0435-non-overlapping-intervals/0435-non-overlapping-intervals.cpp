class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int count = 0;
        vector<pair<int,int>> pr;
        for(int i=0;i<n;i++){
            pr.push_back({intervals[i][1],intervals[i][0]});
        }
        sort(pr.begin(),pr.end());
        int x = 0;
        for(auto it:pr){
            intervals[x][0] = it.second;
            intervals[x][1] = it.first;
            x++;
        }
        int val = intervals[0][1];
        for(int i=1;i<n;i++){
            if(intervals[i][0]<val){
                count++;
            }
            else{
                val = intervals[i][1];
            }
        }
        return count;
    }
};