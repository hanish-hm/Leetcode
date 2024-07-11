class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ans(n,vector<int>(m,0));
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 0){
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
            }
        }
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int step = q.front().second;
            q.pop();
            ans[r][c] = step;
            
            for(int i=0;i<4;i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr<n && nr>=0 && nc < m && nc>=0 && vis[nr][nc] == 0){
                    vis[nr][nc] = 1;
                    q.push({{nr,nc},step+1});
                }
            }
        }
        return ans;
    }
};
