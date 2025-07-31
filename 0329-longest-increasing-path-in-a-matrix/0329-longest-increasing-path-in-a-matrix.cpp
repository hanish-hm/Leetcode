class Solution {
public:
    int func(vector<vector<int>>& matrix,vector<vector<int>>& vec,int r, int c,int m, int n){
        if(vec[r][c]!=-1){
            return vec[r][c];
        }
        int ar1[] = {-1,0,1,0};
        int ar2[] = {0,1,0,-1};
        int maxi = 1;
        for(int i=0;i<4;i++){
            int nr = r+ar1[i];
            int nc = c+ar2[i];
            if(nr>=0&&nr<n&&nc>=0&&nc<m&&matrix[nr][nc]>matrix[r][c]){
                int length = func(matrix,vec,nr,nc,m,n);
                maxi = max(maxi,1+length);
            }
        }
        return vec[r][c] = maxi;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;
        vector<vector<int>> vec(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans = max(ans,func(matrix,vec,i,j,m,n));
            }
        }
        return ans;
    }
};