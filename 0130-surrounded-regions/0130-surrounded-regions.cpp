class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<char>> vis(n,vector<char> (m,0));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            if(board[i][0]=='O' && !vis[i][0]){
                q.push({i,0});
                vis[i][0] = 1;
            }
            if(board[i][m-1]=='O' && !vis[i][m-1]){
                q.push({i,m-1});
                vis[i][m-1] = 1;
            }
        }
        for(int i=0;i<m;i++){
            if(board[0][i]=='O' && !vis[0][i]){
                q.push({0,i});
                vis[0][i] = 1;
            }
            if(board[n-1][i]=='O' && !vis[n-1][i]){
                q.push({n-1,i});
                vis[n-1][i] = 1;
            }
        }
        int arr1[] = {1,0,-1,0};
        int arr2[] = {0,-1,0,1};
        while(!q.empty()){
            int a = q.front().first;
            int b = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int na = a+arr1[i];
                int nb = b+arr2[i];
                if(na>=0 && na<n && nb>=0 && nb<m && board[na][nb] == 'O' && !vis[na][nb]){
                    q.push({na,nb});
                    vis[na][nb] = 1;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == 'O' && !vis[i][j]){
                    board[i][j] = 'X';
                }
            }
        }

    }
};