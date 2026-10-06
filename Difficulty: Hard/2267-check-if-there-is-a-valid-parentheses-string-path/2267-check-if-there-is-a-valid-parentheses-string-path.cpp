class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // A valid parentheses string must have even length
        if ((m + n - 1) % 2 != 0)
            return false;

        // dp[i][j][balance]
        vector<vector<vector<bool>>> dp(
            m,
            vector<vector<bool>>(
                n,
                vector<bool>(m + n, false)
            )
        );

        // Starting cell must be '('
        if (grid[0][0] == ')')
            return false;

        dp[0][0][1] = true;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                // Skip starting cell
                if (i == 0 && j == 0)
                    continue;

                int change = (grid[i][j] == '(') ? 1 : -1;

                for (int balance = 0; balance <= m + n; balance++) {

                    int prevBalance = balance - change;

                    if (prevBalance < 0)
                        continue;

                    bool possible = false;

                    // Come from above
                    if (i > 0 && dp[i - 1][j][prevBalance])
                        possible = true;

                    // Come from left
                    if (j > 0 && dp[i][j - 1][prevBalance])
                        possible = true;

                    if (possible)
                        dp[i][j][balance] = true;
                }
            }
        }

        // Valid string must finish with balance 0
        return dp[m - 1][n - 1][0];
    }
};