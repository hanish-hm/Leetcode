class Solution {
    
public:
    
    void bfs(int n, int m, vector<vector<int>> &vis, vector<vector<int>> &grid, int x, int y){
        queue<pair<int,int>> q;
        q.push({x,y});
        vis[x][y] = 1;
        
        int arr1[] = {-1,0,1,0};
        int arr2[] = {0,1,0,-1};
        
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for(int i = 0; i<4;i++){
                int nx = x + arr1[i];
                int ny = y + arr2[i];
                
                if(nx < n && nx>=0 && ny>=0 && ny<m && grid[nx][ny] == 1 && !vis[nx][ny]){
                    q.push({nx,ny});
                    vis[nx][ny] = 1;
                }
            }
        }
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n,vector<int> (m,0));
        for(int i = 0; i < n; i++){
        if(grid[i][0] == 1 && !vis[i][0]){
            bfs(n, m, vis, grid, i, 0);
        }
        if(grid[i][m-1] == 1 && !vis[i][m-1]){
            bfs(n, m, vis, grid, i, m-1);
        }
    }

    // Traverse boundary columns
    for(int j = 0; j < m; j++){
        if(grid[0][j] == 1 && !vis[0][j]){
            bfs(n, m, vis, grid, 0, j);
        }
        if(grid[n-1][j] == 1 && !vis[n-1][j]){
            bfs(n, m, vis, grid, n-1, j);
        }
    }
        
        int count = 0;
        for(int i = 1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    count++;
                }
            }
        }
        
        return count;
    }
};