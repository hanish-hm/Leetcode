class Solution {
public:
    bool isvalid(char c,int x,int y,vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            if(board[x][i] == c){
                return false;
            }
            if(board[i][y] == c){
                return false;
            }
            if(board[3*(x/3)+i/3][3*(y/3)+i%3] == c){
                return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        int n = board.size();
        int m = board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == '.'){
                    for(char c = '1';c<='9';c++){
                        if(isvalid(c,i,j,board)){
                            board[i][j] = c;
                            if(solve(board)){
                                return true;
                            }
                            else{
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};