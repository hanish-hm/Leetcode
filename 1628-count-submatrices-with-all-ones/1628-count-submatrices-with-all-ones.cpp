class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> height(n, 0);
        int result = 0;

        for (int i = 0; i < m; i++) {
            // Build histogram heights
            for (int j = 0; j < n; j++) {
                height[j] = (mat[i][j] == 0) ? 0 : height[j] + 1;
            }

            // Monotonic stack to count submatrices
            stack<int> st;
            vector<int> sum(n, 0);
            for (int j = 0; j < n; j++) {
                while (!st.empty() && height[st.top()] >= height[j]) {
                    st.pop();
                }

                if (!st.empty()) {
                    int prev = st.top();
                    sum[j] = sum[prev] + height[j] * (j - prev);
                } else {
                    sum[j] = height[j] * (j + 1);
                }

                st.push(j);
                result += sum[j];
            }
        }

        return result;
    }
};
