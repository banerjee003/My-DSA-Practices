class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();

        // pal[i][j] = whether s[i...j] is palindrome
        vector<vector<bool>> pal(n, vector<bool>(n, false));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {

                if (s[i] == s[j] &&
                    (j - i + 1 <= 2 || pal[i + 1][j - 1])) {
                    pal[i][j] = true;
                }
            }
        }

        // dp[i] = maximum palindromes in s[0...i-1]
        vector<int> dp(n + 1, 0);

        for (int j = 0; j < n; j++) {

            // Don't take any palindrome ending at j
            dp[j + 1] = dp[j];

            // Try every palindrome ending at j
            for (int i = 0; i <= j; i++) {

                if (j - i + 1 >= k && pal[i][j]) {
                    dp[j + 1] = max(dp[j + 1], dp[i] + 1);
                }
            }
        }

        return dp[n];
    }
};