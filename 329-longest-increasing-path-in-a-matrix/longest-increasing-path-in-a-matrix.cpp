class Solution {
public:
    vector<vector<int>> dp;

    int rec(int i, int j, vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        if(dp[i][j] != -1)
            return dp[i][j];

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        int ans = 1;

        for(int d = 0; d < 4; d++) {
            int nx = i + dx[d];
            int ny = j + dy[d];

            if(nx >= 0 && nx < m && ny >= 0 && ny < n) {
                if(matrix[nx][ny] > matrix[i][j]) {
                    ans = max(ans, 1 + rec(nx, ny, matrix));
                }
            }
        }

        return dp[i][j] = ans;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        dp.assign(m, vector<int>(n, -1));

        int ans = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                ans = max(ans, rec(i, j, matrix));
            }
        }

        return ans;
    }
};