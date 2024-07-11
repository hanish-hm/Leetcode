class Solution {
public:
    void solve(vector<vector<char>>& board) {
    int n = board.size();
    if (n == 0) return;  // Handle edge case where board is empty
    int m = board[0].size();
    
    // Traverse the board and mark 'O' cells connected to the boundary
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            // Check for 'O' cells on the boundary or connected to the boundary
            if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) && board[i][j] == 'O') {
                // Perform a depth-first search or mark these cells temporarily
                dfs(board, i, j);
            }
        }
    }
    
    // Convert marked 'O' to 'X', and revert temporary marks back to 'O'
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if (board[i][j] == 'O') {
                board[i][j] = 'X';
            } else if (board[i][j] == '#') {
                board[i][j] = 'O';
            }
        }
    }
}

// Depth-first search to mark 'O' cells connected to the boundary
void dfs(vector<vector<char>>& board, int i, int j) {
    int n = board.size();
    int m = board[0].size();
    
    if (i < 0 || i >= n || j < 0 || j >= m || board[i][j] != 'O') {
        return;
    }
    
    // Mark the cell temporarily
    board[i][j] = '#';
    
    // Recursively mark adjacent cells
    dfs(board, i + 1, j);
    dfs(board, i - 1, j);
    dfs(board, i, j + 1);
    dfs(board, i, j - 1);
}

};