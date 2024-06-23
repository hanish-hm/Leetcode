class Solution {
private:
    void bfs(int startRow, int startCol, int initialColor, int newColor, vector<vector<int>>& image) {
        image[startRow][startCol] = newColor;
        queue<pair<int, int>> q;
        q.push({startRow, startCol});
        int directionRow[] = {-1, 0, 1, 0};
        int directionCol[] = {0, 1, 0, -1};
        int numRows = image.size();
        int numCols = image[0].size();
        
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for (int i = 0; i < 4; i++) {
                int newRow = row + directionRow[i];
                int newCol = col + directionCol[i];
                
                if (newRow >= 0 && newRow < numRows && newCol >= 0 && newCol < numCols && image[newRow][newCol] == initialColor) {
                    image[newRow][newCol] = newColor;
                    q.push({newRow, newCol});
                }
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int initialColor = image[sr][sc];
        if (initialColor != newColor) {
            bfs(sr, sc, initialColor, newColor, image);
        }
        return image;
    }
};
