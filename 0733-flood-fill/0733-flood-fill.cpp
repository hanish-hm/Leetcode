class Solution {
private:
    void bfs(vector<vector<int>>& image, int sr, int sc, int n, int m, int color){
        int orignalcolor = image[sr][sc];
        if(orignalcolor == color){
            return;
        }
        image[sr][sc] = color;
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int ar1[] = {-1,0,1,0};
        int ar2[] = {0,-1,0,1};
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr = r+ar1[i];
                int nc = c+ar2[i];
                if(nr>=0&&nr<n&&nc>=0&&nc<m&&image[nr][nc]==orignalcolor){
                    q.push({nr,nc});
                    image[nr][nc] = color;
                }
            }
        }
        return;
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        bfs(image,sr,sc,n,m,color);
        return image;
    }
};