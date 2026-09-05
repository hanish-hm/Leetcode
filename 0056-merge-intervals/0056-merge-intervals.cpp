#include <bits/stdc++.h>
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> merged;
        sort(intervals.begin(),intervals.end());
        merged.push_back(intervals[0]);
        for(int i=1;i<n;i++){
            if(intervals[i][0]<=merged.back()[1]){
                merged.back()[1] = max(intervals[i][1],merged.back()[1]);
            }
            else{
                merged.push_back(intervals[i]);
            }
        }
        return merged;
    }
};