class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        if(n==1 && m==1){
            return 0;
        }
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        vector<vector<int>> effort(n,vector<int>(m,1e9));
        effort[0][0] = 0;
        int arr1[] = {-1,0,1,0};
        int arr2[] = {0,1,0,-1};
        while(!pq.empty()){
            int diff = pq.top().first;
            int a = pq.top().second.first;
            int b = pq.top().second.second;
            int val = heights[a][b];
            pq.pop();
            for(int i=0;i<4;i++){
                int na = a+arr1[i];
                int nb = b+arr2[i];
                if(na<n && na>=0 && nb<m && nb>=0){
                    int neweffort = max(abs(heights[na][nb]-val),diff);
                    if(neweffort < effort[na][nb]){
                        effort[na][nb] = neweffort;
                        pq.push({neweffort,{na,nb}});
                    }
                }
            }
        }
        return effort[n-1][m-1];
    }
};