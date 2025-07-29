class Solution {
private:
    void bfs(vector<vector<char>>& grid,vector<vector<bool>>& visitedland,int i,int j,int rows,int cols){
        visitedland[i][j] = true;
        int ar1[] = {-1,0,1,0};
        int ar2[] = {0,-1,0,1};
        queue<pair<int,int>> q;
        q.push({i,j});
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int newr = r + ar1[i];
                int newc = c + ar2[i];
                if(newr>=0&&newr<rows&&newc>=0&&newc<cols&&!visitedland[newr][newc]&&grid[newr][newc]=='1'){
                    q.push({newr,newc});
                    visitedland[newr][newc] = true;
                }
            }
        }
        return;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int islands = 0;
        vector<vector<bool>> visitedland(rows,vector<bool>(cols,false));
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j] == '1' && !visitedland[i][j]){
                    bfs(grid,visitedland,i,j,rows,cols);
                    islands++;
                }
            }
        }
        return islands;
    }
};