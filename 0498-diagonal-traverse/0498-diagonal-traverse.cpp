class Solution {
public:
    void trav(int row, int col, vector<vector<int>>& mat, vector<int>& ans, int n, int m, int direction) {
    vector<int> x;
    while (row < n && col < m && row >= 0 && col >= 0) { // Correct boundary check
        x.push_back(mat[row][col]);
        row--;
        col++;
    }
    if (direction == 0) {
        reverse(x.begin(), x.end());
    }
    for (int val : x) {
        ans.push_back(val);
    }
}

vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    vector<int> ans;

    // First loop: diagonals starting from first column
    for (int i = 0; i < n; i++) {  // ✅ changed m -> n
        if (i % 2 == 0) {
            trav(i, 0, mat, ans, n, m, 1);
        } else {
            trav(i, 0, mat, ans, n, m, 0);
        }
    }

    // Second loop: diagonals starting from top row (excluding [0,0])
    for (int i = 1; i < m; i++) {
        if ((n + i - 1) % 2 == 0) { // ✅ diagonal index check
            trav(n - 1, i, mat, ans, n, m, 1);
        } else {
            trav(n - 1, i, mat, ans, n, m, 0);
        }
    }

    return ans;
}

};