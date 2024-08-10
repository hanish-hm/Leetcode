class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
            if(grid[0][0] != 0){
                        return -1;
                    }
            if(n==1){
                return 1;
            }
            queue<pair<pair<int,int>,int>> q;
            q.push({{0,0},1});
            vector<vector<int>> dist(n,vector<int>(n,1e9));
            dist[0][0] = 1;
            while(!q.empty()){
                int a = q.front().first.first;
                int b = q.front().first.second;
                int dis = q.front().second;
                q.pop();
                for(int i=-1;i<=1;i++){
                    for(int j=-1;j<=1;j++){
                        int na = a+i;
                        int nb = b+j;
                        if(na<n && na>=0 && nb<n && nb>=0 && grid[na][nb] == 0 &&           dis+1<dist[na][nb]){
                        dist[na][nb] = dis+1;
                        q.push({{na,nb},dist[na][nb]});
                        if(na == n-1 && nb == n-1){
                            return dist[na][nb];
                        }
                    }
                    }
                }
            }
            return -1;
    }
};