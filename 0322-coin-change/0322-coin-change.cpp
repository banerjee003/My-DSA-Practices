class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n+1, vector<int>(amount+1, amount+1));

        for(int i = 1; i <= n; i++){
            dp[i][0] = 0;
        }

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= amount; j++){
                if(coins[i-1] <= j){
                    int ans1 = dp[i][j - coins[i-1]] + 1;
                    int ans2 = dp[i-1][j];
                    dp[i][j] = min(ans1, ans2);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[n][amount] > amount ? -1 : dp[n][amount];
    }
};
