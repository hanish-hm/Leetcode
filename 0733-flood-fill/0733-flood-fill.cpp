class Solution {
private:
    void bfs(int sr,int sc,int curr,int color,vector<vector<int>>& image){
        image[sr][sc] = color;
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int arr1[] = {-1,0,1,0};
        int arr2[] = {0,1,0,-1};
        int n = image.size();
        int m = image[0].size();
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr = row + arr1[i];
                int nc = col + arr2[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && image[nr][nc] == curr){
                    image[nr][nc] = color;
                    q.push({nr,nc});
                }
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int currcolor = image[sr][sc];
        if(currcolor != color){
            bfs(sr,sc,currcolor,color,image);
        }
        return image;
    }
};