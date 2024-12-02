class Solution {
private:
    void bfs(vector<vector<int>>& vis,int x,int y,vector<vector<char>>& grid,int n,int m){
        queue<pair<int,int>> q;
        q.push({x,y});
        vis[x][y] = 1;
        int arr1[] = {-1,0,1,0};
        int arr2[] = {0,1,0,-1};
        while(!q.empty()){
            int a = q.front().first;
            int b = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nx = a+arr1[i];
                int ny = b+arr2[i];
                if(nx<n && nx>=0 && ny<m && ny>=0 && !vis[nx][ny] && grid[nx][ny] == '1'){
                    vis[nx][ny] = 1;
                    q.push({nx,ny});
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n= grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    count++;
                    bfs(vis,i,j,grid,n,m);
                }
            }
        }
        return count;
    }
};