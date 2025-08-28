class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = n;
        for(int i=0;i<n-1;i++){
            int x = i;
            int y = m-1;
            vector<int> a;
            while(x>=0&&y>=0){
                a.push_back(grid[x][y]);
                x--;
                y--;
            }
            sort(a.begin(),a.end(),greater<int>());
            x = i;
            y=m-1;
            int idx = 0;
            while (x >= 0 && y >= 0) {
                grid[x][y] = a[idx++];
                x--; y--;
            }
        }
        for(int i=m-1;i>=0;i--){
            int x = n-1;
            int y = i;
            vector<int> a;
            while(x>=0&&y>=0){
                a.push_back(grid[x][y]);
                x--;
                y--;
            }
            sort(a.begin(),a.end());
            x = n-1;
            y = i;
            int idx = 0;
            while (x >= 0 && y >= 0) {
                grid[x][y] = a[idx];
                idx++;
                x--; y--;
            }
        }
        return grid;
    }
};